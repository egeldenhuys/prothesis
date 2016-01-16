/* funkybutton.h
 * =============
 *
 * DESCRIPTION:
 * ------------
 * Provides a button that when clicked gets the text
 * from the static variable and changes its own text.
 *
 * EXAMPLE:
 * --------
 * - Set the static variable.
 * - When the FunkyButton is clicked, it will change its
 * text to the static var
*/

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
