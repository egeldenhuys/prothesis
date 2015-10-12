#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private slots:


    void on_btnRed_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_btnColTheme_1_clicked();

    void on_btnColTheme_2_clicked();

    void on_btnColTheme_3_clicked();

    void on_btnColTheme_4_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
