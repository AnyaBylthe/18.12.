// user.h
#ifndef USER_H
#define USER_H

#include <string>

class User {
 public:
  std::string _name;
  std::string _login;
  std::string _pass;

  User(const std::string& name, const std::string& login,
       const std::string& pass);
};

#endif  // USER_H
