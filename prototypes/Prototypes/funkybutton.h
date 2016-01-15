#ifndef FUNKYBUTTON_H
#define FUNKYBUTTON_H

#include <QPushButton>

class FunkyButton : public QPushButton
{
    Q_OBJECT

public:
    FunkyButton();
    FunkyButton(QWidget *parent);

    static QString globalColour;
    QString colour;


public slots:
    void applyColour();
};

#endif // FUNKYBUTTON_H
