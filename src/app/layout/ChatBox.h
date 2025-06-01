#ifndef CHATBOX_H
#define CHATBOX_H

#include "app/ChatManager.h"

#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

class ChatBox : public QWidget {
  Q_OBJECT

public:
  explicit ChatBox(QWidget *parent = nullptr);
  ~ChatBox() override;

  // Setters
  void newChat(const id_t &id, const User &user1, const User &user2);

private:
  ChatManager chatManager;
  QVBoxLayout *layout = nullptr;
};

#endif // !CHATBOX_H
