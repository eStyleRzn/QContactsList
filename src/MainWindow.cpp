#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "ContactsView.h"

//======================================================================================================================
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  setCentralWidget(new ContactsView(this));
}

MainWindow::~MainWindow()
{
  delete ui;
}
