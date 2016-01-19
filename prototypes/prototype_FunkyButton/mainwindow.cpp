#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CreateFunkyButton();

    FunkyButton *wat = new FunkyButton();
    wat->setGeometry(50, 50, 50, 50);

    buttonList.append(wat);

    ui->vlButtons->addWidget(buttonList.last());

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

void MainWindow::CreateFunkyButton()
{

    btnFunky = new FunkyButton();
    btnFunky->setParent(this);
    btnFunky->setGeometry(QRect(QPoint(150, 180),
                                QSize(200, 27)));
    btnFunky->setText("Created from code");
}
