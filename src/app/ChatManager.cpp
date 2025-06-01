#include "app/ChatManager.h"
#include "app/class/Chat.h"

#include <nlohmann/json.hpp>

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

ChatManager::ChatManager() {
  std::ifstream jsonDatabase(fileName);

  if (!jsonDatabase.is_open()) {
    writeDatabase();
  }

  db = nlohmann::json::parse(jsonDatabase);

  jsonDatabase.close();
}

void ChatManager::writeDatabase() const {
  std::ofstream jsonOutput(fileName);

  // if (!jsonOutput.is_open()) {
  //   throw database_error("Failed to open and write database");
  // }

  jsonOutput << std::setw(4) << db << std::endl;

  jsonOutput.close();
}

void ChatManager::addChat(const Chat &chat) {
  nlohmann::json jsonChat;

  id_t id = db.size() + 1;
  jsonChat["from"] = chat.getIdFrom();
  jsonChat["to"] = chat.getIdTo();
  jsonChat["messages"] = nlohmann::json::array();

  for (auto const &message : chat.getMessages()) {
    jsonChat["messages"].push_back({{"sender", message.sender},
                                    {"content", message.content},
                                    {"timestamp", message.timestamp}});
  }

  db[std::to_string(id)] = jsonChat;

  writeDatabase();
}

void ChatManager::removeChat(unsigned int id) {
  db.erase(std::to_string(id));

  writeDatabase();
}
