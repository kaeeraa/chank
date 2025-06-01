
#ifndef MESSAGE_H
#define MESSAGE_H

#include "app/class/User.h"

#include <chrono>
#include <string>

using timestamp_t = uint64_t;

class Message {
public:
  // Fields
  id_t id; // id of message should be assigned by database
  id_t sender;
  std::string content;
  timestamp_t timestamp;

  // Constructors
  Message(User const &sender, std::string const &content)
      : sender(sender.id), content(content) {
    timestamp = std::chrono::duration_cast<std::chrono::seconds>(
                    std::chrono::system_clock::now().time_since_epoch())
                    .count();
  }

  // Setters
  void updateContent(std::string_view const &newContent) {
    this->content = newContent;
    this->timestamp = std::chrono::duration_cast<std::chrono::seconds>(
                          std::chrono::system_clock::now().time_since_epoch())
                          .count();
  }
};

#endif // !MESSAGE_H