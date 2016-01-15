#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "funkybutton.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    colour = ui->txtColour->text();
    ui->pushButton->setText(colour);

    FunkyButton::globalColour = colour;
}
