#include "ColouredButton.h"

QString ColouredButton::globalColour = "255, 255, 255";

ColouredButton::ColouredButton()
{
    connect(this, SIGNAL(clicked()),this,SLOT(ApplyColourClicked()));
}

ColouredButton::ColouredButton(QWidget *parent)
{
    this->setParent(parent);
    connect(this, SIGNAL(clicked()),this,SLOT(ApplyColourClicked()));

}

void ColouredButton::ApplyColourClicked()
{
    colour = globalColour;

    this->setStyleSheet("background-color: rgb(" + colour + ");");
}

void ColouredButton::ApplyColour(QString newColour)
{
    colour = newColour;

    this->setStyleSheet("background-color: rgb(" + colour + ");");
}


