#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->checkBox, countBox::countChangedSignal, this, updateStuff);
}

void MainWindow::updateStuff(int val)
{
    ui->txtCounter->setText(QString::fromStdString(std::to_string(val)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
