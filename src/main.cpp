#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  QLabel label("hello world!");
  label.show();

  return QApplication::exec();
}