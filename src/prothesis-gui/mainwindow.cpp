#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QLineEdit>
#include <string>
#include "../tests.h"
#include "../user.h"
#include "../globals.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //run_tests();
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

    // ======================
    // Sub Interests START
    // ======================
    if (UserData.subInterests.size() >= 1)
         ui->txtSubInterest1->setText(QString::fromStdString(UserData.subInterests[0]));
    if (UserData.subInterests.size() >= 2)
         ui->txtSubInterest2->setText(QString::fromStdString(UserData.subInterests[1]));
    if (UserData.subInterests.size() >= 3)
         ui->txtSubInterest3->setText(QString::fromStdString(UserData.subInterests[2]));

    // =======================
    // Sub Interests Perc START
    // =======================
    if (UserData.subInterestsPerc.size() >= 1)
         ui->spnbSubIntertest1->setValue(QString::fromStdString(UserData.subInterestsPerc[0]).toInt());
    if (UserData.subInterestsPerc.size() >= 2)
         ui->spnbSubIntertest2->setValue(QString::fromStdString(UserData.subInterestsPerc[1]).toInt());
    if (UserData.subInterestsPerc.size() >= 3)
         ui->spnbSubIntertest3->setValue(QString::fromStdString(UserData.subInterestsPerc[2]).toInt());

    // =======================
    // Roles Start
    // =======================

    // Add all role checkboxes to a vector of QCheckBox

    std::vector<QCheckBox*> roleBoxes;

    roleBoxes.push_back(ui->chkbRoles_1);
    roleBoxes.push_back(ui->chkbRoles_2);
    roleBoxes.push_back(ui->chkbRoles_3);
    roleBoxes.push_back(ui->chkbRoles_4);
    roleBoxes.push_back(ui->chkbRoles_5);
    roleBoxes.push_back(ui->chkbRoles_6);
    roleBoxes.push_back(ui->chkbRoles_7);
    roleBoxes.push_back(ui->chkbRoles_8);
    roleBoxes.push_back(ui->chkbRoles_9);
    roleBoxes.push_back(ui->chkbRoles_10);
    roleBoxes.push_back(ui->chkbRoles_11);
    roleBoxes.push_back(ui->chkbRoles_12);
    roleBoxes.push_back(ui->chkbRoles_13);
    roleBoxes.push_back(ui->chkbRoles_14);
    roleBoxes.push_back(ui->chkbRoles_15);
    roleBoxes.push_back(ui->chkbRoles_16);
    roleBoxes.push_back(ui->chkbRoles_17);
    roleBoxes.push_back(ui->chkbRoles_18);
    roleBoxes.push_back(ui->chkbRoles_19);
    roleBoxes.push_back(ui->chkbRoles_20);
    roleBoxes.push_back(ui->chkbRoles_21);
    roleBoxes.push_back(ui->chkbRoles_22);
    roleBoxes.push_back(ui->chkbRoles_23);
    roleBoxes.push_back(ui->chkbRoles_24);
    roleBoxes.push_back(ui->chkbRoles_25);
    roleBoxes.push_back(ui->chkbRoles_26);
    roleBoxes.push_back(ui->chkbRoles_27);
    roleBoxes.push_back(ui->chkbRoles_28);
    roleBoxes.push_back(ui->chkbRoles_29);
    roleBoxes.push_back(ui->chkbRoles_30);
    roleBoxes.push_back(ui->chkbRoles_31);
    roleBoxes.push_back(ui->chkbRoles_32);
    roleBoxes.push_back(ui->chkbRoles_33);
    roleBoxes.push_back(ui->chkbRoles_34);


    // Loop through loaded box names and check those that exist


    // Loop through all Loaded roles
    for (uint i = 0; i < UserData.roles.size(); i++)
    {
        // Loop through all  Checkboxes
        for (uint j = 0; j < roleBoxes.size(); j++)
        {
            if (roleBoxes.at(j)->text() == QString::fromStdString(UserData.roles.at(i)))
                roleBoxes.at(j)->setChecked(1);
        }
    }

    // =======================
    // Skills Start
    // =======================

    // Add all role checkboxes to a vector of QCheckBox

    std::vector<QCheckBox*> skillBoxes;

    skillBoxes.push_back(ui->chkbSkills_1);
    skillBoxes.push_back(ui->chkbSkills_2);
    skillBoxes.push_back(ui->chkbSkills_3);
    skillBoxes.push_back(ui->chkbSkills_4);
    skillBoxes.push_back(ui->chkbSkills_5);
    skillBoxes.push_back(ui->chkbSkills_6);
    skillBoxes.push_back(ui->chkbSkills_7);
    skillBoxes.push_back(ui->chkbSkills_8);
    skillBoxes.push_back(ui->chkbSkills_9);
    skillBoxes.push_back(ui->chkbSkills_10);
    skillBoxes.push_back(ui->chkbSkills_11);
    skillBoxes.push_back(ui->chkbSkills_12);
    skillBoxes.push_back(ui->chkbSkills_13);
    skillBoxes.push_back(ui->chkbSkills_14);
    skillBoxes.push_back(ui->chkbSkills_15);
    skillBoxes.push_back(ui->chkbSkills_16);
    skillBoxes.push_back(ui->chkbSkills_17);
    skillBoxes.push_back(ui->chkbSkills_18);
    skillBoxes.push_back(ui->chkbSkills_19);
    skillBoxes.push_back(ui->chkbSkills_20);
    skillBoxes.push_back(ui->chkbSkills_21);
    skillBoxes.push_back(ui->chkbSkills_22);
    skillBoxes.push_back(ui->chkbSkills_23);
    skillBoxes.push_back(ui->chkbSkills_24);
    skillBoxes.push_back(ui->chkbSkills_25);
    skillBoxes.push_back(ui->chkbSkills_26);
    skillBoxes.push_back(ui->chkbSkills_27);
    skillBoxes.push_back(ui->chkbSkills_28);
    skillBoxes.push_back(ui->chkbSkills_29);
    skillBoxes.push_back(ui->chkbSkills_30);


    // Loop through loaded box names and check those that exist


    // Loop through all Loaded roles
    for (uint i = 0; i < UserData.skills.size(); i++)
    {
        // Loop through all  Checkboxes
        for (uint j = 0; j < skillBoxes.size(); j++)
        {
            if (skillBoxes.at(j)->text() == QString::fromStdString(UserData.skills.at(i)))
                skillBoxes.at(j)->setChecked(1);
        }
    }


    // =======================
    // Strengths Start
    // =======================

    // Add all role checkboxes to a vector of QCheckBox

    std::vector<QCheckBox*> strengthBoxes;

    strengthBoxes.push_back(ui->chkbStrengths_1);
    strengthBoxes.push_back(ui->chkbStrengths_2);
    strengthBoxes.push_back(ui->chkbStrengths_3);
    strengthBoxes.push_back(ui->chkbStrengths_4);
    strengthBoxes.push_back(ui->chkbStrengths_5);
    strengthBoxes.push_back(ui->chkbStrengths_6);
    strengthBoxes.push_back(ui->chkbStrengths_7);
    strengthBoxes.push_back(ui->chkbStrengths_8);
    strengthBoxes.push_back(ui->chkbStrengths_9);
    strengthBoxes.push_back(ui->chkbStrengths_10);
    strengthBoxes.push_back(ui->chkbStrengths_11);
    strengthBoxes.push_back(ui->chkbStrengths_12);
    strengthBoxes.push_back(ui->chkbStrengths_13);
    strengthBoxes.push_back(ui->chkbStrengths_14);
    strengthBoxes.push_back(ui->chkbStrengths_15);
    strengthBoxes.push_back(ui->chkbStrengths_16);
    strengthBoxes.push_back(ui->chkbStrengths_17);
    strengthBoxes.push_back(ui->chkbStrengths_18);
    strengthBoxes.push_back(ui->chkbStrengths_19);
    strengthBoxes.push_back(ui->chkbStrengths_20);
    strengthBoxes.push_back(ui->chkbStrengths_21);
    strengthBoxes.push_back(ui->chkbStrengths_22);
    strengthBoxes.push_back(ui->chkbStrengths_23);
    strengthBoxes.push_back(ui->chkbStrengths_24);
    strengthBoxes.push_back(ui->chkbStrengths_25);
    strengthBoxes.push_back(ui->chkbStrengths_26);
    strengthBoxes.push_back(ui->chkbStrengths_27);
    strengthBoxes.push_back(ui->chkbStrengths_28);
    strengthBoxes.push_back(ui->chkbStrengths_29);
    strengthBoxes.push_back(ui->chkbStrengths_30);
    strengthBoxes.push_back(ui->chkbStrengths_31);
    strengthBoxes.push_back(ui->chkbStrengths_32);
    strengthBoxes.push_back(ui->chkbStrengths_33);


    // Loop through loaded box names and check those that exist


    // Loop through all Loaded roles
    for (uint i = 0; i < UserData.strengths.size(); i++)
    {
        // Loop through all  Checkboxes
        for (uint j = 0; j < strengthBoxes.size(); j++)
        {
            if (strengthBoxes.at(j)->text() == QString::fromStdString(UserData.strengths.at(i)))
                strengthBoxes.at(j)->setChecked(1);
        }
    }

    // ======================
    // Passion START
    // ======================

    ui->txtPassionsAlive->setText(QString::fromStdString(UserData.passionsAlive));
    ui->txtPassionsChange->setText(QString::fromStdString(UserData.passionsChange));
    ui->txtPassionsGiveUp->setText(QString::fromStdString(UserData.passionsGiveUp));
    ui->txtPassionsMovie->setText(QString::fromStdString(UserData.passionsMovie));
    ui->txtPassionsOneThing->setText(QString::fromStdString(UserData.passionsMovie));
    ui->txtPassionsSummary->setPlainText(QString::fromStdString(UserData.passionsSummary));

    // ======================
    // Dreams START
    // ======================

    ui->txtDreamsChild->setText(QString::fromStdString(UserData.dreamsChild));
    ui->txtDreamsCurrent->setText(QString::fromStdString(UserData.dreamsCurrent));
    ui->txtDreamsPasttime->setText(QString::fromStdString(UserData.dreamsPasttime));
    ui->txtDreamSummary->setPlainText(QString::fromStdString(UserData.dreamsSummary));


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

    // ======================
    // Sub Interests START
    // ======================

    // Clear the current vector
    UserData.subInterests.clear();

    UserData.subInterests.push_back(ui->txtSubInterest1->text().toStdString());
    UserData.subInterests.push_back(ui->txtSubInterest2->text().toStdString());
    UserData.subInterests.push_back(ui->txtSubInterest3->text().toStdString());

    // ======================
    // Sub Interests Perc START
    // ======================

    // Clear the current vector
    UserData.subInterestsPerc.clear();

    UserData.subInterestsPerc.push_back(std::to_string(ui->spnbSubIntertest1->value()));
    UserData.subInterestsPerc.push_back(std::to_string(ui->spnbSubIntertest2->value()));
    UserData.subInterestsPerc.push_back(std::to_string(ui->spnbSubIntertest3->value()));


    // =======================
    // Roles Start
    // =======================

    // Add all role checkboxes to a vector of QCheckBox

    std::vector<QCheckBox*> roleBoxes;

    roleBoxes.push_back(ui->chkbRoles_1);
    roleBoxes.push_back(ui->chkbRoles_2);
    roleBoxes.push_back(ui->chkbRoles_3);
    roleBoxes.push_back(ui->chkbRoles_4);
    roleBoxes.push_back(ui->chkbRoles_5);
    roleBoxes.push_back(ui->chkbRoles_6);
    roleBoxes.push_back(ui->chkbRoles_7);
    roleBoxes.push_back(ui->chkbRoles_8);
    roleBoxes.push_back(ui->chkbRoles_9);
    roleBoxes.push_back(ui->chkbRoles_10);
    roleBoxes.push_back(ui->chkbRoles_11);
    roleBoxes.push_back(ui->chkbRoles_12);
    roleBoxes.push_back(ui->chkbRoles_13);
    roleBoxes.push_back(ui->chkbRoles_14);
    roleBoxes.push_back(ui->chkbRoles_15);
    roleBoxes.push_back(ui->chkbRoles_16);
    roleBoxes.push_back(ui->chkbRoles_17);
    roleBoxes.push_back(ui->chkbRoles_18);
    roleBoxes.push_back(ui->chkbRoles_19);
    roleBoxes.push_back(ui->chkbRoles_20);
    roleBoxes.push_back(ui->chkbRoles_21);
    roleBoxes.push_back(ui->chkbRoles_22);
    roleBoxes.push_back(ui->chkbRoles_23);
    roleBoxes.push_back(ui->chkbRoles_24);
    roleBoxes.push_back(ui->chkbRoles_25);
    roleBoxes.push_back(ui->chkbRoles_26);
    roleBoxes.push_back(ui->chkbRoles_27);
    roleBoxes.push_back(ui->chkbRoles_28);
    roleBoxes.push_back(ui->chkbRoles_29);
    roleBoxes.push_back(ui->chkbRoles_30);
    roleBoxes.push_back(ui->chkbRoles_31);
    roleBoxes.push_back(ui->chkbRoles_32);
    roleBoxes.push_back(ui->chkbRoles_33);
    roleBoxes.push_back(ui->chkbRoles_34);


    // Loop through all the boxes and save the checked names

    UserData.roles.clear();

    for (uint i = 0; i < roleBoxes.size(); i++)
    {

        if (roleBoxes.at(i)->checkState() == 2)
            UserData.roles.push_back(roleBoxes.at(i)->text().toStdString());

    }


    // =======================
    // Skills Start
    // =======================

    // Add all role checkboxes to a vector of QCheckBox

    std::vector<QCheckBox*> skillBoxes;

    skillBoxes.push_back(ui->chkbSkills_1);
    skillBoxes.push_back(ui->chkbSkills_2);
    skillBoxes.push_back(ui->chkbSkills_3);
    skillBoxes.push_back(ui->chkbSkills_4);
    skillBoxes.push_back(ui->chkbSkills_5);
    skillBoxes.push_back(ui->chkbSkills_6);
    skillBoxes.push_back(ui->chkbSkills_7);
    skillBoxes.push_back(ui->chkbSkills_8);
    skillBoxes.push_back(ui->chkbSkills_9);
    skillBoxes.push_back(ui->chkbSkills_10);
    skillBoxes.push_back(ui->chkbSkills_11);
    skillBoxes.push_back(ui->chkbSkills_12);
    skillBoxes.push_back(ui->chkbSkills_13);
    skillBoxes.push_back(ui->chkbSkills_14);
    skillBoxes.push_back(ui->chkbSkills_15);
    skillBoxes.push_back(ui->chkbSkills_16);
    skillBoxes.push_back(ui->chkbSkills_17);
    skillBoxes.push_back(ui->chkbSkills_18);
    skillBoxes.push_back(ui->chkbSkills_19);
    skillBoxes.push_back(ui->chkbSkills_20);
    skillBoxes.push_back(ui->chkbSkills_21);
    skillBoxes.push_back(ui->chkbSkills_22);
    skillBoxes.push_back(ui->chkbSkills_23);
    skillBoxes.push_back(ui->chkbSkills_24);
    skillBoxes.push_back(ui->chkbSkills_25);
    skillBoxes.push_back(ui->chkbSkills_26);
    skillBoxes.push_back(ui->chkbSkills_27);
    skillBoxes.push_back(ui->chkbSkills_28);
    skillBoxes.push_back(ui->chkbSkills_29);
    skillBoxes.push_back(ui->chkbSkills_30);


    // Loop through all the boxes and save the checked names

    UserData.skills.clear();

    for (uint i = 0; i < skillBoxes.size(); i++)
    {

        if (skillBoxes.at(i)->checkState() == 2)
            UserData.skills.push_back(skillBoxes.at(i)->text().toStdString());
    }


    // =======================
    // Strengths Start
    // =======================

    // Add all role checkboxes to a vector of QCheckBox

    std::vector<QCheckBox*> strengthBoxes;

    strengthBoxes.push_back(ui->chkbStrengths_1);
    strengthBoxes.push_back(ui->chkbStrengths_2);
    strengthBoxes.push_back(ui->chkbStrengths_3);
    strengthBoxes.push_back(ui->chkbStrengths_4);
    strengthBoxes.push_back(ui->chkbStrengths_5);
    strengthBoxes.push_back(ui->chkbStrengths_6);
    strengthBoxes.push_back(ui->chkbStrengths_7);
    strengthBoxes.push_back(ui->chkbStrengths_8);
    strengthBoxes.push_back(ui->chkbStrengths_9);
    strengthBoxes.push_back(ui->chkbStrengths_10);
    strengthBoxes.push_back(ui->chkbStrengths_11);
    strengthBoxes.push_back(ui->chkbStrengths_12);
    strengthBoxes.push_back(ui->chkbStrengths_13);
    strengthBoxes.push_back(ui->chkbStrengths_14);
    strengthBoxes.push_back(ui->chkbStrengths_15);
    strengthBoxes.push_back(ui->chkbStrengths_16);
    strengthBoxes.push_back(ui->chkbStrengths_17);
    strengthBoxes.push_back(ui->chkbStrengths_18);
    strengthBoxes.push_back(ui->chkbStrengths_19);
    strengthBoxes.push_back(ui->chkbStrengths_20);
    strengthBoxes.push_back(ui->chkbStrengths_21);
    strengthBoxes.push_back(ui->chkbStrengths_22);
    strengthBoxes.push_back(ui->chkbStrengths_23);
    strengthBoxes.push_back(ui->chkbStrengths_24);
    strengthBoxes.push_back(ui->chkbStrengths_25);
    strengthBoxes.push_back(ui->chkbStrengths_26);
    strengthBoxes.push_back(ui->chkbStrengths_27);
    strengthBoxes.push_back(ui->chkbStrengths_28);
    strengthBoxes.push_back(ui->chkbStrengths_29);
    strengthBoxes.push_back(ui->chkbStrengths_30);
    strengthBoxes.push_back(ui->chkbStrengths_31);
    strengthBoxes.push_back(ui->chkbStrengths_32);
    strengthBoxes.push_back(ui->chkbStrengths_33);


    // Loop through all the boxes and save the checked names

    UserData.strengths.clear();

    for (uint i = 0; i < strengthBoxes.size(); i++)
    {

        if (strengthBoxes.at(i)->checkState() == 2)
            UserData.strengths.push_back(strengthBoxes.at(i)->text().toStdString());
    }

    // ======================
    // Passions START
    // ======================

    UserData.passionsAlive = ui->txtPassionsAlive->text().toStdString();
    UserData.passionsChange = ui->txtPassionsChange->text().toStdString();
    UserData.passionsGiveUp = ui->txtPassionsGiveUp->text().toStdString();
    UserData.passionsMovie = ui->txtPassionsMovie->text().toStdString();
    UserData.passionsOneThing = ui->txtPassionsOneThing->text().toStdString();
    UserData.passionsSummary = ui->txtPassionsSummary->document()->toPlainText().toStdString();


    // ======================
    // Dreams START
    // ======================

    UserData.dreamsChild = ui->txtDreamsChild->text().toStdString();
    UserData.dreamsCurrent = ui->txtDreamsCurrent->text().toStdString();
    UserData.dreamsPasttime = ui->txtDreamsPasttime->text().toStdString();
    UserData.dreamsSummary = ui->txtDreamSummary->document()->toPlainText().toStdString();


    // ====================
    // END
    // ====================

    UserData.save();
}
