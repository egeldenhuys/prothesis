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
   SaveUserData();

   delete ui;
}

/* MainWindow::LoadUserData()
 * ==========================
 *
 * Description:
 *      This function loads the user data from the data file
 *      and displays it on the GUI
 *
*/
void MainWindow::LoadUserData() {

    UserData.load();

    // ======================
    // Name And Surname START
    // ======================

    ui->txtName->setText(QString::fromStdString(UserData.name));
    ui->txtSurname->setText(QString::fromStdString(UserData.surname));

    // ======================
    // MBTI START
    // ======================

    // If the length is less than 4, it has not been loaded
    if (UserData.mbti.length() == 4) {

        // Need to convert to QString to be able to easily manipulate
        QString mbti;
        mbti = QString::fromStdString(UserData.mbti);

        // Set combo boxes
        ui->cmbMBTI1->setCurrentText(mbti.at(0));
        ui->cmbMBTI2->setCurrentText(mbti.at(1));
        ui->cmbMBTI3->setCurrentText(mbti.at(2));
        ui->cmbMBTI4->setCurrentText(mbti.at(3));
    }

    // ======================
    // Life Keys START
    // ======================

   if (UserData.lifeKeys.size() >= 1)
        ui->txtLifeKey1->setText(QString::fromStdString(UserData.lifeKeys[0]));

    if (UserData.lifeKeys.size() >= 2)
        ui->txtLifeKey2->setText(QString::fromStdString(UserData.lifeKeys[1]));

    if (UserData.lifeKeys.size() == 3)
        ui->txtLifeKey3->setText(QString::fromStdString(UserData.lifeKeys[2]));

}

/* MainWindow::SaveUserData()
 * ==========================
 *
 * Description:
 *      This function saves the user data that has been
 *      set on the GUI to the data file
 *
 * Notes:
 *      Overwrites the existing data
*/
void MainWindow::SaveUserData() {

    // ======================
    // Name And Surname START
    // ======================

    UserData.name = ui->txtName->text().toStdString();
    UserData.surname = ui->txtSurname->text().toStdString();


    // ======================
    // MBTI START
    // ======================

    QString mbti;

    mbti.append(ui->cmbMBTI1->currentText());
    mbti.append(ui->cmbMBTI2->currentText());
    mbti.append(ui->cmbMBTI3->currentText());
    mbti.append(ui->cmbMBTI4->currentText());

    UserData.mbti = mbti.toStdString();

    // ======================
    // Life Keys START
    // ======================

    // Clear the current life keys
    UserData.lifeKeys.clear();

    // Assign the new new life keys
    UserData.lifeKeys.push_back(ui->txtLifeKey1->text().toStdString());
    UserData.lifeKeys.push_back(ui->txtLifeKey2->text().toStdString());
    UserData.lifeKeys.push_back(ui->txtLifeKey3->text().toStdString());


    UserData.save();
}
