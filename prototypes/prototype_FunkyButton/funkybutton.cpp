#include "funkybutton.h"

QString FunkyButton::globalColour = "NONE";

FunkyButton::FunkyButton()
{
    connect(this, SIGNAL(clicked()),this,SLOT(applyColour()));
}

FunkyButton::FunkyButton(QWidget *parent)
{
    this->setParent(parent);
    connect(this, SIGNAL(clicked()),this,SLOT(applyColour()));

}

void FunkyButton::applyColour()
{
    colour = globalColour;

    this->setText(colour);
}
