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

    // ======================
    // Interests START
    // ======================

    if (UserData.interests.size() >= 1)
         ui->txtInterest1->setText(QString::fromStdString(UserData.interests[0]));
    if (UserData.interests.size() >= 2)
         ui->txtInterest2->setText(QString::fromStdString(UserData.interests[1]));
    if (UserData.interests.size() >= 3)
         ui->txtInterest3->setText(QString::fromStdString(UserData.interests[2]));
    if (UserData.interests.size() == 4)
         ui->txtInterest4->setText(QString::fromStdString(UserData.interests[3]));

    // ======================
    // Interests Perc START
    // ======================
    if (UserData.interestsPerc.size() >= 1)
         ui->spnbInternest1->setValue(QString::fromStdString(UserData.interestsPerc[0]).toInt());
    if (UserData.interestsPerc.size() >= 2)
         ui->spnbInternest2->setValue(QString::fromStdString(UserData.interestsPerc[1]).toInt());
    if (UserData.interestsPerc.size() >= 3)
         ui->spnbInternest3->setValue(QString::fromStdString(UserData.interestsPerc[2]).toInt());
    if (UserData.interestsPerc.size() == 4)
         ui->spnbInternest4->setValue(QString::fromStdString(UserData.interestsPerc[3]).toInt());

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

    // ======================
    // Interests START
    // ======================

    // Clear the current vector
    UserData.interests.clear();

    UserData.interests.push_back(ui->txtInterest1->text().toStdString());
    UserData.interests.push_back(ui->txtInterest2->text().toStdString());
    UserData.interests.push_back(ui->txtInterest3->text().toStdString());
    UserData.interests.push_back(ui->txtInterest4->text().toStdString());


    // ======================
    // Interests Perc START
    // ======================

    // Clear the current vector
    UserData.interestsPerc.clear();

    UserData.interestsPerc.push_back(std::to_string(ui->spnbInternest1->value()));
    UserData.interestsPerc.push_back(std::to_string(ui->spnbInternest2->value()));
    UserData.interestsPerc.push_back(std::to_string(ui->spnbInternest3->value()));
    UserData.interestsPerc.push_back(std::to_string(ui->spnbInternest4->value()));


    UserData.save();
}
