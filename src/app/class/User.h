#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
  // Fields
  std::string username;
  id_t id;

  User(std::string const &username, id_t id) : username(username), id(id) {}
};

#endif // !USER_H
