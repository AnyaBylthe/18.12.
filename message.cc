// message.cc
#include "message.h"

#include <fstream>
#include <iostream>

Message::Message(const std::string& text, const std::string& sender,
                 const std::string& receiver)
    : _text(text), _sender(sender), _receiver(receiver) {}

bool saveMessageState(const Message& message, const std::string& filename) {
  std::ofstream outFile(filename);
  if (outFile.is_open()) {
    outFile << message._text << std::endl;
    outFile << message._sender << std::endl;
    outFile << message._receiver << std::endl;
    outFile.close();
    return true;
  } else {
    std::cerr << "Unable to open file for writing: " << filename << std::endl;
    return false;
  }
}

Message loadMessageState(const std::string& filename) {
  Message message("", "", "");
  std::ifstream inFile(filename);
  if (inFile.is_open()) {
    getline(inFile, message._text);
    getline(inFile, message._sender);
    getline(inFile, message._receiver);
    inFile.close();
  } else {
    std::cerr << "Unable to open file for reading: " << filename << std::endl;
  }
  return message;
}
