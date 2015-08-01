#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QLineEdit>
#include <string>

#include "../user.h"
#include "../globals.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    LoadUserData();
}

MainWindow::~MainWindow()
{
    // Save Data
   SaveUserData();
    delete ui;
}

void MainWindow::LoadUserData() {
    // Load Data
    UserData.load();

    // Display Data

    // Name and Surname
    ui->txtName->setText(QString::fromStdString(UserData.name));
    ui->txtSurname->setText(QString::fromStdString(UserData.surname));

    // TODO
    // MBTI
    //if (UserData.mbti != std::string::)
    //    ui->cmbMBTI1->highlighted(1);
    // Life Keys
   if (UserData.lifeKeys.size() >= 1)
        ui->txtLifeKey1->setText(QString::fromStdString(UserData.lifeKeys[0]));

    if (UserData.lifeKeys.size() >= 2)
        ui->txtLifeKey2->setText(QString::fromStdString(UserData.lifeKeys[1]));

    if (UserData.lifeKeys.size() == 3)
        ui->txtLifeKey3->setText(QString::fromStdString(UserData.lifeKeys[2]));

}


void MainWindow::SaveUserData() {
    // Name and Surname
    UserData.name = ui->txtName->text().toStdString();
    UserData.surname = ui->txtSurname->text().toStdString();

    // Life Keys

    // We need to clear the vector because we cannot assign a value
    // to a vector element that does not exist
    // So we start it from scratch
    UserData.lifeKeys.clear();

    UserData.lifeKeys.push_back(ui->txtLifeKey1->text().toStdString());
    UserData.lifeKeys.push_back(ui->txtLifeKey2->text().toStdString());
    UserData.lifeKeys.push_back(ui->txtLifeKey3->text().toStdString());

    UserData.save();
}
