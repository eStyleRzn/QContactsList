#include "MainWindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QFile file(":/styles.qss");
  if(file.open(QIODevice::ReadOnly | QIODevice::Text))
  {
    a.setStyleSheet(file.readAll());
    file.close();
  }

  MainWindow w;
  w.show();

  return a.exec();
}
