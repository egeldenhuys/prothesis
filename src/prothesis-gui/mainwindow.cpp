#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QLineEdit>
#include <string>
#include "../tests.h"
#include "../user.h"
#include "../globals.h"
#include <QCoreApplication>
#include <stdio.h>
#include "button_list.h"
#include <QMessageBox>

QString colour;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->chkbRoles_1->startInitialize();

    //run_tests();
    LoadUserData();
    SetMBTI();

    loadButtons();
    SetAnalysisTextboxes();

   this->setWindowTitle("Prothesis - " + VERSION);
}

button_list *btnListRoles;
button_list *btnListSkills;
button_list *btnListPriorities;
button_list *btnListPeople;
button_list *btnListStrengths;
button_list *btnListLifeKeys;


/*
 * Button List Algorithm
 * =====================
 *
 * User checks a checkbox
 * Analysis tab is clicked (Data is saved and added to UserClass)
 * Update() is called on the Button List
*/
void MainWindow::loadButtons()
{
 // Create a button for each Role that has been loaded

    btnListRoles = new button_list(ui->vlRoles, &UserData.roles);

    for (uint i = 0; i < UserData.buttonsRoleNames.size(); i++)
        btnListRoles->change_colour(UserData.buttonsRoleNames[i], UserData.buttonsRoleColours[i]);

    btnListSkills = new button_list(ui->vlSkills, &UserData.skills);

    for (uint i = 0; i < UserData.buttonsSkillsNames.size(); i++)
        btnListSkills->change_colour(UserData.buttonsSkillsNames[i], UserData.buttonsSkillsColours[i]);

    btnListPriorities = new button_list(ui->vlPriorities, &UserData.priorities);

    for (uint i = 0; i < UserData.buttonsPrioritiesNames.size(); i++)
        btnListPriorities->change_colour(UserData.buttonsPrioritiesNames[i], UserData.buttonsPrioritiesColours[i]);

    btnListPeople = new button_list(ui->vlPeople, &UserData.people);

    for (uint i = 0; i < UserData.buttonsPeopleNames.size(); i++)
        btnListPeople->change_colour(UserData.buttonsPeopleNames[i], UserData.buttonsPeopleColours[i]);

    btnListStrengths = new button_list(ui->vlStrengths, &UserData.strengths);

    for (uint i = 0; i < UserData.buttonsStrengthsNames.size(); i++)
        btnListStrengths->change_colour(UserData.buttonsStrengthsNames[i], UserData.buttonsStrengthsColours[i]);

    btnListLifeKeys = new button_list(ui->vlLifeKeys, &UserData.lifeKeys);


    for (uint i = 0; i < UserData.buttonsLifeKeysNames.size(); i++)
        btnListLifeKeys->change_colour(UserData.buttonsLifeKeysNames[i], UserData.buttonsLifeKeysColours[i]);

}

void MainWindow::saveButtons()
{
    updateButtonLists();

    UserData.buttonsRoleNames.clear();
    UserData.buttonsRoleColours.clear();

    for (int i = 0; i < btnListRoles->cButtonList_.size(); i++)
    {
        UserData.buttonsRoleNames.push_back(btnListRoles->cButtonList_.at(i)->text().toStdString());
        UserData.buttonsRoleColours.push_back(btnListRoles->cButtonList_.at(i)->colour.toStdString());
    }


    UserData.buttonsSkillsNames.clear();
    UserData.buttonsSkillsColours.clear();

    for (int i = 0; i < btnListSkills->cButtonList_.size(); i++)
    {
        UserData.buttonsSkillsNames.push_back(btnListSkills->cButtonList_.at(i)->text().toStdString());
        UserData.buttonsSkillsColours.push_back(btnListSkills->cButtonList_.at(i)->colour.toStdString());
    }


    UserData.buttonsPrioritiesNames.clear();
    UserData.buttonsPrioritiesColours.clear();

    for (int i = 0; i < btnListPriorities->cButtonList_.size(); i++)
    {
        UserData.buttonsPrioritiesNames.push_back(btnListPriorities->cButtonList_.at(i)->text().toStdString());
        UserData.buttonsPrioritiesColours.push_back(btnListPriorities->cButtonList_.at(i)->colour.toStdString());
    }


    UserData.buttonsPeopleNames.clear();
    UserData.buttonsPeopleColours.clear();

    for (int i = 0; i < btnListPeople->cButtonList_.size(); i++)
    {
        UserData.buttonsPeopleNames.push_back(btnListPeople->cButtonList_.at(i)->text().toStdString());
        UserData.buttonsPeopleColours.push_back(btnListPeople->cButtonList_.at(i)->colour.toStdString());
    }


    UserData.buttonsStrengthsNames.clear();
    UserData.buttonsStrengthsColours.clear();

    for (int i = 0; i < btnListStrengths->cButtonList_.size(); i++)
    {
        UserData.buttonsStrengthsNames.push_back(btnListStrengths->cButtonList_.at(i)->text().toStdString());
        UserData.buttonsStrengthsColours.push_back(btnListStrengths->cButtonList_.at(i)->colour.toStdString());
    }


    UserData.buttonsLifeKeysNames.clear();
    UserData.buttonsLifeKeysColours.clear();

    for (int i = 0; i < btnListLifeKeys->cButtonList_.size(); i++)
    {
        UserData.buttonsLifeKeysNames.push_back(btnListLifeKeys->cButtonList_.at(i)->text().toStdString());
        UserData.buttonsLifeKeysColours.push_back(btnListLifeKeys->cButtonList_.at(i)->colour.toStdString());
    }

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

    ui->txtRecommendation->setPlainText(QString::fromStdString(UserData.recommendation));

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
    strengthBoxes.push_back(ui->chkbStrengths_34);

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
    ui->txtPassionsOneThing->setText(QString::fromStdString(UserData.passionsOneThing));
    ui->txtPassionsSummary->setPlainText(QString::fromStdString(UserData.passionsSummary));

    // ======================
    // Dreams START
    // ======================

    ui->txtDreamsChild->setText(QString::fromStdString(UserData.dreamsChild));
    ui->txtDreamsCurrent->setText(QString::fromStdString(UserData.dreamsCurrent));
    ui->txtDreamsPasttime->setText(QString::fromStdString(UserData.dreamsPasttime));
    ui->txtDreamSummary->setPlainText(QString::fromStdString(UserData.dreamsSummary));

    // ======================
    // People ID START
    // ======================

    ui->txtpeopleInfluence->setPlainText(QString::fromStdString(UserData.peopleInfluence));
    ui->txtPeopleCharacter->setPlainText(QString::fromStdString(UserData.peopleCharacter));
    ui->txtPeopleHero->setPlainText(QString::fromStdString(UserData.peopleHero));
    ui->txtPeopleIdentify->setPlainText(QString::fromStdString(UserData.peopleIdentify));
    ui->txtPeopleSummary->setPlainText(QString::fromStdString(UserData.peopleSummary));

    // ======================
    // Spoken Words START
    // ======================

    ui->ptxtSpokenSummary->setPlainText(QString::fromStdString(UserData.spokenSummary));
    ui->ptxtSpokenWords->setPlainText(QString::fromStdString(UserData.spokenWords));

    // =======================
    // People Orientation Start
    // =======================

    // Add all role checkboxes to a vector of QCheckBox

    std::vector<QCheckBox*> peopleBoxes;

    peopleBoxes.push_back(ui->chkbPeople_1);
    peopleBoxes.push_back(ui->chkbPeople_2);
    peopleBoxes.push_back(ui->chkbPeople_3);
    peopleBoxes.push_back(ui->chkbPeople_4);
    peopleBoxes.push_back(ui->chkbPeople_5);
    peopleBoxes.push_back(ui->chkbPeople_6);
    peopleBoxes.push_back(ui->chkbPeople_7);
    peopleBoxes.push_back(ui->chkbPeople_8);
    peopleBoxes.push_back(ui->chkbPeople_9);
    peopleBoxes.push_back(ui->chkbPeople_10);
    peopleBoxes.push_back(ui->chkbPeople_11);
    peopleBoxes.push_back(ui->chkbPeople_12);
    peopleBoxes.push_back(ui->chkbPeople_13);
    peopleBoxes.push_back(ui->chkbPeople_14);
    peopleBoxes.push_back(ui->chkbPeople_15);
    peopleBoxes.push_back(ui->chkbPeople_16);


    // Loop through loaded box names and check those that exist


    // Loop through all Loaded roles
    for (uint i = 0; i < UserData.people.size(); i++)
    {
        // Loop through all  Checkboxes
        for (uint j = 0; j < peopleBoxes.size(); j++)
        {
            if (peopleBoxes.at(j)->text() == QString::fromStdString(UserData.people.at(i)))
                peopleBoxes.at(j)->setChecked(1);
        }
    }

    // =======================
    // Priorities Start
    // =======================

    // Add all role checkboxes to a vector of QCheckBox

    std::vector<QCheckBox*> priorityBoxes;

    priorityBoxes.push_back(ui->chkbPriorities_1);
    priorityBoxes.push_back(ui->chkbPriorities_2);
    priorityBoxes.push_back(ui->chkbPriorities_3);
    priorityBoxes.push_back(ui->chkbPriorities_4);
    priorityBoxes.push_back(ui->chkbPriorities_5);
    priorityBoxes.push_back(ui->chkbPriorities_6);
    priorityBoxes.push_back(ui->chkbPriorities_7);
    priorityBoxes.push_back(ui->chkbPriorities_8);
    priorityBoxes.push_back(ui->chkbPriorities_9);
    priorityBoxes.push_back(ui->chkbPriorities_10);


    // Loop through loaded box names and check those that exist


    // Loop through all Loaded roles
    for (uint i = 0; i < UserData.priorities.size(); i++)
    {
        // Loop through all  Checkboxes
        for (uint j = 0; j < priorityBoxes.size(); j++)
        {
            if (priorityBoxes.at(j)->text() == QString::fromStdString(UserData.priorities.at(i)))
                priorityBoxes.at(j)->setChecked(1);
        }
    }

    // ======================
    // Work Environment START
    // ======================

    ui->txtWorkCreative->setText(QString::fromStdString(UserData.workCreative));
    ui->txtWorkIdeal->setText(QString::fromStdString(UserData.workIdeal));
    ui->txtWorkStructure->setText(QString::fromStdString(UserData.workStructure));
    ui->txtWorkUndefined->setText(QString::fromStdString(UserData.workUndefined));
    ui->ptxtWorkSummary->setPlainText(QString::fromStdString(UserData.workSummary));

    // ======================
    // Analysis START
    // ======================

    ui->txtTheme_1->setPlainText(QString::fromStdString(UserData.theme1));
    ui->txtTheme_2->setPlainText(QString::fromStdString(UserData.theme2));
    ui->txtTheme_3->setPlainText(QString::fromStdString(UserData.theme3));
    ui->txtTheme_4->setPlainText(QString::fromStdString(UserData.theme4));

    ui->txtTheme_1->setStyleSheet(QString::fromStdString("background-color: rgb(" + UserData.theme1c + ");"));
    ui->txtTheme_2->setStyleSheet(QString::fromStdString("background-color: rgb(" + UserData.theme2c + ");"));
    ui->txtTheme_3->setStyleSheet(QString::fromStdString("background-color: rgb(" + UserData.theme3c + ");"));
    ui->txtTheme_4->setStyleSheet(QString::fromStdString("background-color: rgb(" + UserData.theme4c + ");"));

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

    UserData.recommendation = ui->txtRecommendation->document()->toPlainText().toStdString();

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
    if (ui->txtLifeKey1->text() != "")
        UserData.lifeKeys.push_back(ui->txtLifeKey1->text().toStdString());

    if (ui->txtLifeKey2->text() != "")
        UserData.lifeKeys.push_back(ui->txtLifeKey2->text().toStdString());

    if (ui->txtLifeKey3->text() != "")
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
    strengthBoxes.push_back(ui->chkbStrengths_34);

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

    // ======================
    // People ID START
    // ======================

    UserData.peopleInfluence = ui->txtpeopleInfluence->document()->toPlainText().toStdString();
    UserData.peopleCharacter = ui->txtPeopleCharacter->document()->toPlainText().toStdString();
    UserData.peopleHero = ui->txtPeopleHero->document()->toPlainText().toStdString();
    UserData.peopleIdentify = ui->txtPeopleIdentify->document()->toPlainText().toStdString();
    UserData.peopleSummary = ui->txtPeopleSummary->document()->toPlainText().toStdString();

    // ======================
    // Spoken Words START
    // ======================

    UserData.spokenSummary = ui->ptxtSpokenSummary->document()->toPlainText().toStdString();
    UserData.spokenWords = ui->ptxtSpokenWords->document()->toPlainText().toStdString();

    // =======================
    // People Orientation Start
    // =======================

    // Add all role checkboxes to a vector of QCheckBox

    std::vector<QCheckBox*> peopleBoxes;

    peopleBoxes.push_back(ui->chkbPeople_1);
    peopleBoxes.push_back(ui->chkbPeople_2);
    peopleBoxes.push_back(ui->chkbPeople_3);
    peopleBoxes.push_back(ui->chkbPeople_4);
    peopleBoxes.push_back(ui->chkbPeople_5);
    peopleBoxes.push_back(ui->chkbPeople_6);
    peopleBoxes.push_back(ui->chkbPeople_7);
    peopleBoxes.push_back(ui->chkbPeople_8);
    peopleBoxes.push_back(ui->chkbPeople_9);
    peopleBoxes.push_back(ui->chkbPeople_10);
    peopleBoxes.push_back(ui->chkbPeople_11);
    peopleBoxes.push_back(ui->chkbPeople_12);
    peopleBoxes.push_back(ui->chkbPeople_13);
    peopleBoxes.push_back(ui->chkbPeople_14);
    peopleBoxes.push_back(ui->chkbPeople_15);
    peopleBoxes.push_back(ui->chkbPeople_16);


    // Loop through all the boxes and save the checked names

    UserData.people.clear();

    for (uint i = 0; i < peopleBoxes.size(); i++)
    {

        if (peopleBoxes.at(i)->checkState() == 2)
            UserData.people.push_back(peopleBoxes.at(i)->text().toStdString());
    }


    // =======================
    // Priorities Start
    // =======================

    // Add all role checkboxes to a vector of QCheckBox

    std::vector<QCheckBox*> priorityBoxes;

    priorityBoxes.push_back(ui->chkbPriorities_1);
    priorityBoxes.push_back(ui->chkbPriorities_2);
    priorityBoxes.push_back(ui->chkbPriorities_3);
    priorityBoxes.push_back(ui->chkbPriorities_4);
    priorityBoxes.push_back(ui->chkbPriorities_5);
    priorityBoxes.push_back(ui->chkbPriorities_6);
    priorityBoxes.push_back(ui->chkbPriorities_7);
    priorityBoxes.push_back(ui->chkbPriorities_8);
    priorityBoxes.push_back(ui->chkbPriorities_9);
    priorityBoxes.push_back(ui->chkbPriorities_10);



    // Loop through all the boxes and save the checked names

    UserData.priorities.clear();

    for (uint i = 0; i < priorityBoxes.size(); i++)
    {

        if (priorityBoxes.at(i)->checkState() == 2)
            UserData.priorities.push_back(priorityBoxes.at(i)->text().toStdString());
    }

    // ======================
    // Passions START
    // ======================

    UserData.workCreative = ui->txtWorkCreative->text().toStdString();
    UserData.workIdeal = ui->txtWorkIdeal->text().toStdString();
    UserData.workStructure = ui->txtWorkStructure->text().toStdString();
    UserData.workUndefined = ui->txtWorkUndefined->text().toStdString();
    UserData.workSummary = ui->ptxtWorkSummary->document()->toPlainText().toStdString();

    // ======================
    // Analysis START
    // ======================

    UserData.theme1 = ui->txtTheme_1->document()->toPlainText().toStdString();
    UserData.theme2 = ui->txtTheme_2->document()->toPlainText().toStdString();
    UserData.theme3 = ui->txtTheme_3->document()->toPlainText().toStdString();
    UserData.theme4 = ui->txtTheme_4->document()->toPlainText().toStdString();

    // Colours are directly set

    saveButtons();

    // ====================
    // END
    // ====================

    UserData.save();
}

void MainWindow::SetColour(QString newColour) {
    colour = newColour;

    ui->btnColour->setStyleSheet("background-color: rgb(" + newColour + ");");
    ui->btnColTheme_1->setStyleSheet("background-color: rgb(" + newColour + ");");
    ui->btnColTheme_2->setStyleSheet("background-color: rgb(" + newColour + ");");
    ui->btnColTheme_3->setStyleSheet("background-color: rgb(" + newColour + ");");
    ui->btnColTheme_4->setStyleSheet("background-color: rgb(" + newColour + ");");

    ColouredButton::globalColour = colour;
}

void MainWindow::on_btnRed_clicked()
{
    SetColour("231, 150, 150");
}


void MainWindow::on_btnColTheme_1_clicked()
{
    ui->txtTheme_1->setStyleSheet("background-color: rgb(" + colour + ");");
    UserData.theme1c = colour.toStdString();

}

void MainWindow::on_btnColTheme_2_clicked()
{
    ui->txtTheme_2->setStyleSheet("background-color: rgb(" + colour + ");");
    UserData.theme2c = colour.toStdString();
}

void MainWindow::on_btnColTheme_3_clicked()
{
    ui->txtTheme_3->setStyleSheet("background-color: rgb(" + colour + ");");
    UserData.theme3c = colour.toStdString();
}

void MainWindow::on_btnColTheme_4_clicked()
{
    ui->txtTheme_4->setStyleSheet("background-color: rgb(" + colour + ");");
    UserData.theme4c = colour.toStdString();
}

void MainWindow::on_cmbMBTI1_currentTextChanged(const QString &arg1)
{
    //SaveUserData();
    ui->txtMBTI_1->setText(arg1);
    SetMBTI();

}

void MainWindow::on_cmbMBTI2_currentTextChanged(const QString &arg1)
{
   // SaveUserData();
    ui->txtMBTI_2->setText(arg1);
    SetMBTI();
}

void MainWindow::on_cmbMBTI3_currentTextChanged(const QString &arg1)
{
    //SaveUserData();
    ui->txtMBTI_3->setText(arg1);
    SetMBTI();
}

void MainWindow::on_cmbMBTI4_currentTextChanged(const QString &arg1)
{
    //SaveUserData();
    ui->txtMBTI_4->setText(arg1);
    SetMBTI();
}

void MainWindow::SetMBTI()
{
    QString mbti1, mbti2, mbti3, mbti4;

    mbti1 = ui->txtMBTI_1->text();
    mbti2 = ui->txtMBTI_2->text();
    mbti3 = ui->txtMBTI_3->text();
    mbti4 = ui->txtMBTI_4->text();

    if (mbti1 == "E")
    {
        ui->lblMBTI_1->setText("Outward focus, communication, energy");
        ui->lblMBTI_B_1->setText("Direct involvement and implementation");
    }

    if (mbti1 == "I")
    {
        ui->lblMBTI_1->setText("Thinkers, concepts, writing, alone time");
        ui->lblMBTI_B_1->setText("Direct or indirect involvement and implementation with enough time alone");
    }

    if (mbti2 == "S")
    {
        ui->lblMBTI_2->setText("Practical and detail orientated");
    }

    if (mbti2 == "N")
    {
        ui->lblMBTI_2->setText("Innovative, holistic, see new possibilities");
    }

    if (mbti3 == "T")
    {
        ui->lblMBTI_3->setText("Objective, analytical, logical");
    }

    if (mbti3 == "F")
    {
        ui->lblMBTI_3->setText("People oriented, sympathetic, personal");
    }

    if (mbti4 == "J")
    {
        ui->lblMBTI_4->setText("Order, control, structure");\
        ui->lblMBTI_B_3->setText("Organized, structured and conclusive environment");
    }

    if (mbti4 == "P")
    {
        ui->lblMBTI_4->setText("Flexible, spontaneous, philosophical");
        ui->lblMBTI_B_3->setText("Spontaneous and flexible environment");
    }

    if (mbti2 == "N" && mbti3 == "F")
    {
        ui->lblMBTI_B_2->setText("You will be innovative in the development of people on a more personal basis");

    }

    if (mbti2 == "N" && mbti3 == "T")
    {
        ui->lblMBTI_B_2->setText("You will be innovative in some of the following: development of systems, patents, organizations, management or people on a less personal level");

    }

    if (mbti2 == "S" && mbti3 == "F")
    {
        ui->lblMBTI_B_2->setText("You will want to help people by working hands on and in a practical manner with them");

    }

    if (mbti2 == "S" && mbti3 == "T")
    {
        ui->lblMBTI_B_2->setText("You will want to manage or bring practical solutions to systems, organizations, management or people on a less personal level");

    }
}

void MainWindow::on_btnGreen_clicked()
{
    SetColour("158, 255, 161");
}

void MainWindow::on_btnBlue_clicked()
{
    SetColour("172, 166, 255");
}

void MainWindow::on_btnYellow_clicked()
{
    SetColour("255, 253, 166");
}

void MainWindow::on_btnWhite_clicked()
{
    SetColour("255, 255, 255");
}

/* Button List
 *
 * Functions:
 * - Get list of items from UserData object
 * - Add button
 * - On button click change color
 * - Clear list
 * -
 * Algorithm
 *
 * Get item from UserData [0: "Analyzer"]
 * Create button with name ["Analyzer"]
 * Set button stylesheet
 * Add button to the layout widget
 *
 * Button List
 * - Buttons
 * - Remove by name
 * - Add button(name, colour)
 *
 * Button
 * - Text
 * - Colour
*/

/* UserData.roles
 * - [String]
 * - Analyzer
 * - Pope
 * - Creator
 * - Mister
 * - Dog manager
 * - Sheep
 * - Farmer
 *
 * UserData.buttonsRoles
 * - [String, String]
 * - Analyzer, 0
 * - Pope, 45
 * - Creator, 74
 * - Mister, 23
 * - Dog manager, 51
 * - Sheep, 8
 * - Farmer, 99
*/

void MainWindow::on_actionAbout_this_software_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("Prothesis - " + VERSION + "\n"
                   "\n"
                   "Please see the included README.txt for more information."
                   "\n"
                   "Developed by: Evert Geldenhuys.\n\n"
                   ""
                   "Source Code is available on GitHub:\n"
                   "https://github.com/egeldenhuys/prothesis");
    msgBox.exec();
}

void MainWindow::updateButtonLists()
{

    btnListRoles->update();
    btnListSkills->update();
    btnListPriorities->update();
    btnListPeople->update();
    btnListStrengths->update();
    btnListLifeKeys->update();

}
void MainWindow::on_tabWidget_currentChanged(int index)
{
    SaveUserData();

    if (index == 3)
    {

        updateButtonLists();
        SetAnalysisTextboxes();

    }


}

void MainWindow::SetAnalysisTextboxes()
{
    ui->txtPassionsAnalysis->document()->setPlainText(ui->txtPassionsSummary->document()->toPlainText());
    ui->txtPeopleAnalysis->document()->setPlainText(ui->txtPeopleSummary->document()->toPlainText());
    ui->txtDreamsAnalysis->document()->setPlainText(ui->txtDreamSummary->document()->toPlainText());
    ui->txtWordsAnalysis->document()->setPlainText(ui->ptxtSpokenSummary->document()->toPlainText());
    ui->txtWorkAnalysis->document()->setPlainText(ui->ptxtWorkSummary->document()->toPlainText());

    ui->txtInterestAnalysis_1->setText(ui->txtInterest1->text());
    ui->txtInterestAnalysis_2->setText(ui->txtInterest2->text());
    ui->txtInterestAnalysis_3->setText(ui->txtInterest3->text());
    ui->txtInterestAnalysis_4->setText(ui->txtInterest4->text());

    ui->txtSubInterestAnalysis_1->setText(ui->txtSubInterest1->text());
    ui->txtSubInterestAnalysis_2->setText(ui->txtSubInterest2->text());
    ui->txtSubInterestAnalysis_3->setText(ui->txtSubInterest3->text());

    ui->txtIntPercAnalysis_1->setText(ui->spnbInternest1->text() + " %");
    ui->txtIntPercAnalysis_2->setText(ui->spnbInternest2->text() + " %");
    ui->txtIntPercAnalysis_3->setText(ui->spnbInternest3->text() + " %");
    ui->txtIntPercAnalysis_4->setText(ui->spnbInternest4->text() + " %");

    ui->txtSubIntPercAnalysis_1->setText(ui->spnbSubIntertest1->text() + " %");
    ui->txtSubIntPercAnalysis_2->setText(ui->spnbSubIntertest2->text() + " %");
    ui->txtSubIntPercAnalysis_3->setText(ui->spnbSubIntertest3->text() + " %");


}


void MainWindow::on_btnCareerTest_clicked()
{
    //QDesktopServices::openUrl(QUrl("http://www.yourfreecareertest.com/", QUrl::TolerantMode));

    openUrl("http://www.yourfreecareertest.com/");
}

void MainWindow::on_btnCareerTest_2_clicked()
{
    openUrl("http://freestrengthstest.workuno.com/free-strengths-test.html");
}


void MainWindow::on_btnCareerTest_3_clicked()
{
   openUrl("http://www.personalitypage.com/");
}

void MainWindow::openUrl(QString url)
{
    QDesktopServices::openUrl(QUrl(url, QUrl::TolerantMode));
}
