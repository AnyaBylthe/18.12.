#include "user.h"

#include <iostream>

User::User(const std::string &name, const std::string &login,
           const std::string &pass)
    : name_(name), login_(login), pass_(pass) {}

bool saveUserState(const User &user, const std::string &filename) {
  std::ofstream outFile(filename);
  if (outFile.is_open()) {
    outFile << user.name_ << std::endl;
    outFile << user.login_ << std::endl;
    outFile << user.pass_ << std::endl;
    outFile.close();
    return true;
  } else {
    std::cerr << "Unable to open file for writing: " << filename << std::endl;
    return false;
  }
}

User loadUserState(const std::string &filename) {
  User user("", "", "");
  std::ifstream inFile(filename);
  if (inFile.is_open()) {
    getline(inFile, user.name_);
    getline(inFile, user.login_);
    getline(inFile, user.pass_);
    inFile.close();
  } else {
    std::cerr << "Unable to open file for reading: " << filename << std::endl;
  }
  return user;
}
