#include "funkybutton.h"

QString FunkyButton::globalColour = "NONE";

FunkyButton::FunkyButton()
{

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

/*
 * User clicks colour setting button.
 * colour changes
 * user clicks a funky button
 * funky button gets the new colour
 * funky button changes to the new colour
*/

/*
 * colour changes
 * all funky buttons are updated with the new colour
 * funky button is pressed
 * funky button changes to the colour set
*/
