// message.h
#ifndef MESSAGE_H
#define MESSAGE_H

#include <fstream>
#include <string>

class Message {
 public:
  std::string text_;
  std::string sender_;
  std::string receiver_;

  Message(const std::string &text, const std::string &sender,
          const std::string &receiver);
};

#endif  // MESSAGE_H
