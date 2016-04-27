#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <QSpinBox>

std::vector<QSpinBox> boxVector;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createBoxes(5, qobject_cast<QVBoxLayout*>(ui->vlButtons->layout()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn1_clicked()
{

    /*
    // When button is pressed move it to bottom of widget



    int oldIndex = ui->vlButtons->indexOf(ui->btn1);

    std::cout << "Old Index = " << oldIndex << "\n";

    ui->vlButtons->removeWidget(ui->btn1);

    ui->vlButtons->insertWidget(2, ui->btn1);

    std::cout << "new: " << ui->vlButtons->indexOf(ui->btn1) << "\n";

    std::stringstream cat;

    cat << oldIndex;


    ui->btn1->setText("LOL = " + QString::fromStdString(cat.str()));
*/

}

void MainWindow::createBoxes(int count, QVBoxLayout *boxLayout)
{

    // Can't pass layout widget as paramater?

    for (int i = 0; i < count; i++)
    {
        // Create box
        QSpinBox *tmpBox = new QSpinBox(boxLayout->widget());

       // QVBoxLayout *mahLayout = qobject_cast<QVBoxLayout*>(ui->vlButtons->widget()->layout());
        boxLayout->addWidget(tmpBox);

    }
}

void MainWindow::boxChange(int arg1)
{


}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    /*
    QSpinBox *mahSpinBox = ui->spinBox;

    QVBoxLayout *mahLayout = qobject_cast<QVBoxLayout*>(mahSpinBox->parentWidget()->layout());

    mahLayout->removeWidget(mahSpinBox);

    mahLayout->insertWidget(arg1, ui->spinBox);
    */
}
