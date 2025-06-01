#ifndef CHATMANAGER_H
#define CHATMANAGER_H

#include "app/class/Chat.h"

#include <nlohmann/json.hpp>

#include <vector>

class ChatManager {
public:
  // Constructors
  ChatManager();
  // Singleton
  inline static ChatManager &getInstance() {
    static ChatManager instance;
    return instance;
  }
  // Setters
  void addChat(const Chat &chat);
  void removeChat(unsigned int id);
  // Getters
  std::vector<Chat> getChats() const { return chats; }

private:
  // Fields
  const std::string fileName = "database.json";
  nlohmann::json db;
  std::vector<Chat> chats;

  // Methods
  void writeDatabase() const;
};
#endif // !CHATMANAGER_H
