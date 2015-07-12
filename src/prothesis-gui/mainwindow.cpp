#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QLineEdit>

#include "../user.h"
#include "../globals.h"

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

void MainWindow::on_btnLoad_clicked()
{
    UserData.load();
    ui->txtName->setText(QString::fromStdString(UserData.name));
}

void MainWindow::on_btnSave_clicked()
{
    QString name = ui->txtName->text();
    UserData.name = name.toUtf8().constData();
    UserData.save();
}
