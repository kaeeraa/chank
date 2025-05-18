#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "app/ChatBox.h"

#include <memory>

int main(int argc, char **argv) {
  QApplication app(argc, argv);
  auto window = std::make_unique<QWidget>();
  window->setWindowTitle("Chank | Chats");

  auto chatBox = std::make_unique<ChatBox>(window.get());
  window->setLayout(new QVBoxLayout(window.get()));
  window->layout()->addWidget(chatBox.get());

  window->show();
  return QApplication::exec();
}