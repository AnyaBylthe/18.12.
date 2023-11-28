// user.cc
#include "user.h"

#include <fstream>
#include <iostream>

User::User(const std::string& name, const std::string& login,
           const std::string& pass)
    : _name(name), _login(login), _pass(pass) {}

bool saveUserState(const User& user, const std::string& filename) {
  std::ofstream outFile(filename);
  if (outFile.is_open()) {
    outFile << user._name << std::endl;
    outFile << user._login << std::endl;
    outFile << user._pass << std::endl;
    outFile.close();
    return true;
  } else {
    std::cerr << "Unable to open file for writing: " << filename << std::endl;
    return false;
  }
}

User loadUserState(const std::string& filename) {
  User user("", "", "");
  std::ifstream inFile(filename);
  if (inFile.is_open()) {
    getline(inFile, user._name);
    getline(inFile, user._login);
    getline(inFile, user._pass);
    inFile.close();
  } else {
    std::cerr << "Unable to open file for reading: " << filename << std::endl;
  }
  return user;
}
