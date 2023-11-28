#ifndef USER_H
#define USER_H

#include <fstream>
#include <string>

class User {
 public:
  std::string name_;
  std::string login_;
  std::string pass_;

  User(const std::string &name, const std::string &login,
       const std::string &pass);
};

#endif  // USER_H
