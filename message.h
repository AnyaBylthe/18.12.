// message.h
#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message {
 public:
  std::string _text;
  std::string _sender;
  std::string _receiver;

  Message(const std::string& text, const std::string& sender,
          const std::string& receiver);
};

#endif  // MESSAGE_H
