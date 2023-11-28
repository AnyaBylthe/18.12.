// main.cc
#include <iostream>

#include "message.h"
#include "user.h"

// Включаем объявления функций из user.cc и message.cc
extern bool saveUserState(const User& user, const std::string& filename);
extern User loadUserState(const std::string& filename);
extern bool saveMessageState(const Message& message,
                             const std::string& filename);
extern Message loadMessageState(const std::string& filename);

int main() {
  // Пример использования
  User user1("John Doe", "john_doe", "password123");
  Message message1("Hello, World!", "john_doe", "alice");

  // Запись состояния объектов в файлы
  if (saveUserState(user1, "user1.txt")) {
    std::cout << "User state saved successfully." << std::endl;
  } else {
    std::cerr << "Failed to save user state." << std::endl;
  }

  if (saveMessageState(message1, "message1.txt")) {
    std::cout << "Message state saved successfully." << std::endl;
  } else {
    std::cerr << "Failed to save message state." << std::endl;
  }

  // Чтение состояния объектов из файлов
  User loadedUser = loadUserState("user1.txt");
  if (!loadedUser._name.empty()) {
    std::cout << "User state loaded successfully." << std::endl;
  } else {
    std::cerr << "Failed to load user state." << std::endl;
  }

  Message loadedMessage = loadMessageState("message1.txt");
  if (!loadedMessage._text.empty()) {
    std::cout << "Message state loaded successfully." << std::endl;
  } else {
    std::cerr << "Failed to load message state." << std::endl;
  }

  // Вывод загруженных данных
  std::cout << "Loaded User:" << std::endl;
  std::cout << "Name: " << loadedUser._name << std::endl;
  std::cout << "Login: " << loadedUser._login << std::endl;
  std::cout << "Password: " << loadedUser._pass << std::endl;

  std::cout << "\nLoaded Message:" << std::endl;
  std::cout << "Text: " << loadedMessage._text << std::endl;
  std::cout << "Sender: " << loadedMessage._sender << std::endl;
  std::cout << "Receiver: " << loadedMessage._receiver << std::endl;

  return 0;
}
