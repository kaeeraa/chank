#include "app/layout/ChatBox.h"
#include "app/ChatManager.h"
#include "app/class/User.h"

#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

ChatBox::ChatBox(QWidget *parent) : QWidget(parent) {
  layout = new QVBoxLayout(this);
  layout->setAlignment(Qt::AlignLeft);
  layout->addStretch();

  auto *newChatButton = new QPushButton("New Chat", this);

  User user1("user_1", 1);
  User user2("user_2", 2);

  int num = 10;
  connect(newChatButton, &QPushButton::clicked, this,
          [this, &num, &user1, &user2]() mutable {
            num++;
            newChat(num, user1, user2);
          });

  for (int i = 0; i < 3; i++) {
    newChat(i + 1, user1, user2);
  }

  layout->addStretch();
  layout->addWidget(newChatButton);
}

ChatBox::~ChatBox() { delete layout; }

void ChatBox::newChat(const id_t &id, const User &user1, const User &user2) {
  Chat chat(id, user1, user2);

  chat.addMessage(user1, "Hello World!");
  chat.addMessage(user2, "Hii!!");
  chat.addMessage(user1, "How are you? 123");
  chat.addMessage(user2, "I'm fine. 321");

  chatManager.addChat(chat);
}