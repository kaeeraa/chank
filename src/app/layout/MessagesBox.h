#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

class MessagesBox : public QWidget {
public:
  explicit MessagesBox(QWidget *parent = nullptr);

  private:
    QVBoxLayout *layout = nullptr;
    
}

#endif // !MESSAGEBOX_H