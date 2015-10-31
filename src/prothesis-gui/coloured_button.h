#ifndef COLOURED_BUTTON_H
#define COLOURED_BUTTON_H

#include <string>
#include <QPushButton>

using namespace std;

class coloured_button
{
public:
    coloured_button();

    QString name;
    QString colour;

    QPushButton *button;

    void setColour(QString btnColour);
    void setText(QString btnName);

};

#endif // COLOURED_BUTTON_H
