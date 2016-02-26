#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->checkBox->printIndex();

    ui->checkBox->startInitialize();

}

MainWindow::~MainWindow()
{
    delete ui;
}
