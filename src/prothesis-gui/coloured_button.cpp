#include "coloured_button.h"

coloured_button::coloured_button()
{
    button = new QPushButton;
    button->setText("uninitialized!");

}

void coloured_button::setColour(QString btnColour)
{
    colour = btnColour;
    button->setStyleSheet("background-color: rgb(" + colour + ");");

}

void coloured_button::setText(QString btnName)
{
    name = btnName;
    button->setText(name);
}
