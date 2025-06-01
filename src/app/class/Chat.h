#ifndef CHAT_H
#define CHAT_H

#include "app/class/Message.h"
#include "app/class/User.h"

#include <string>
#include <vector>

class Chat {
private:
  // Fields
  id_t idFrom;
  id_t idTo;
  id_t id; // id of chat should be assigned by database
  std::vector<Message> messages;

public:
  // Constructors
  Chat(const id_t &id, const User &from, const User &to)
      : idFrom(from.id), idTo(to.id), id(id) {}
  // Setters
  void addMessage(const User &sender, const std::string &content) {
    messages.emplace_back(sender, content);
  };
  void deleteMessage(const id_t &idMessage) {
    messages.erase(messages.begin() + idMessage);
  };
  // Getters
  std::vector<Message> getMessages() const { return messages; }
  id_t getIdFrom() const { return idFrom; }
  id_t getIdTo() const { return idTo; }
  id_t getId() const { return id; }
};
#endif // !CHAT_H
