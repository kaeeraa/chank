#ifndef CHATBOX_H
#define CHATBOX_H

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>

#include <vector>

class ChatBox : public QWidget {
  Q_OBJECT

public:
  explicit ChatBox(QWidget *parent = nullptr);
  ~ChatBox() override;

private:
  QVBoxLayout *layout = nullptr;
  std::vector<QPushButton *> chats;

public slots:
  void newChat(QString name);
};

#endif // !CHATBOX_H
