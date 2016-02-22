#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "button_list.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void LoadUserData();
    void SaveUserData();
    void SetColour(QString newColour);
    void SetMBTI();
    void loadButtons();
    void linkButton(QPushButton *btn);
    void linkButtons(button_list * buttonList);
    void saveButtons();

private slots:


    void on_btnRed_clicked();

    void on_btnColTheme_1_clicked();

    void on_btnColTheme_2_clicked();

    void on_btnColTheme_3_clicked();

    void on_btnColTheme_4_clicked();

    void on_cmbMBTI1_currentTextChanged(const QString &arg1);

    void on_cmbMBTI2_currentTextChanged(const QString &arg1);

    void on_cmbMBTI3_currentTextChanged(const QString &arg1);

    void on_cmbMBTI4_currentTextChanged(const QString &arg1);

    void on_btnGreen_clicked();

    void on_btnBlue_clicked();

    void on_btnYellow_clicked();

    void on_btnWhite_clicked();

    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
