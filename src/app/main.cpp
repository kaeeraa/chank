#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include <memory>

int main(int argc, char **argv) {
  QApplication app(argc, argv);
  auto window = std::make_unique<QWidget>();
  window->setWindowTitle("Chank | Chats");

  window->show();
  return QApplication::exec();
}