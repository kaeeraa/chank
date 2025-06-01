#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "app/class/User.h"

#include <nlohmann/json.hpp>

#include <vector>

class UserManager {
public:
  UserManager(const UserManager &) = delete;
  UserManager &operator=(const UserManager &) = delete;
  // Singleton
  static UserManager &getInstance() {
    static UserManager instance;
    return instance;
  }
  // Setters
  void addUser(const User &user) { users.push_back(user); }
  void deleteUser(const id_t &id) { users.erase(users.begin() + id); }
  // Getters
  std::vector<User> getUsers() const { return users; }

private:
  // Constructors
  UserManager() = default;
  // Fields
  const std::string fileName = "users.json";
  nlohmann::json db;
  std::vector<User> users;
};
#endif