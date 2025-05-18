#include "ChatBox.h"

#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

ChatBox::ChatBox(QWidget *parent) : QWidget(parent) {
  layout = new QVBoxLayout(this);
  layout->setAlignment(Qt::AlignLeft);
  layout->addStretch();

  auto *newChatButton = new QPushButton("New Chat", this);

  connect(newChatButton, &QPushButton::clicked, this,
          [this] { newChat("New Chat"); });

  for (int i = 0; i < 3; i++) {
    newChat(QString::number(i));
  }

  layout->addStretch();
  layout->addWidget(newChatButton);
}

void ChatBox::newChat(QString name) {
  if (chats.size() >= 10) {
    return;
  }

  auto *newChat = new QPushButton("Chat " + name, this);

  layout->insertWidget(static_cast<int>(chats.size()), newChat);
  chats.push_back(newChat);
}
