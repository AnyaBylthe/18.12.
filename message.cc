// message.cc
#include "message.h"

#include <fstream>
#include <iostream>

Message::Message(const std::string &text, const std::string &sender,
                 const std::string &receiver)
    : text_(text), sender_(sender), receiver_(receiver) {}

bool saveMessageState(const Message &message, const std::string &filename) {
  std::ofstream outFile(filename);
  if (outFile.is_open()) {
    outFile << message.text_ << std::endl;
    outFile << message.sender_ << std::endl;
    outFile << message.receiver_ << std::endl;
    outFile.close();
    return true;
  } else {
    std::cerr << "Unable to open file for writing: " << filename << std::endl;
    return false;
  }
}

Message loadMessageState(const std::string &filename) {
  Message message("", "", "");
  std::ifstream inFile(filename);
  if (inFile.is_open()) {
    getline(inFile, message.text_);
    getline(inFile, message.sender_);
    getline(inFile, message.receiver_);
    inFile.close();
  } else {
    std::cerr << "Unable to open file for reading: " << filename << std::endl;
  }
  return message;
}
