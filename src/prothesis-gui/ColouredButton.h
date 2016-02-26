/* ColouredButton.h
 * ================
 *
 * DESCRIPTION:
 * ------------
 * Provides a button. When this button is clicked it changes its
 * background colour to the rgb value in ColouredButton:globalColour
 *
 * EXAMPLE:
 * --------
 * ColouredButton *myButton = new ColouredButton(this)
 * myButton->setText("My Button");
 *
 * // When myButton is clicked the background colour will be set to:
 * ColouredButton::globalColour = "255, 255, 255";
*/

#ifndef COLOUREDBUTTON_H
#define COLOUREDBUTTON_H

#include <QPushButton>

class ColouredButton : public QPushButton
{
    Q_OBJECT

private:
    Q_DISABLE_COPY(ColouredButton)

public:
    ColouredButton();
    ColouredButton(QWidget *parent);
    void ApplyColour(QString newColour);

    static QString globalColour;
    QString colour;

private slots:
    void ApplyColourClicked();
};

#endif // COLOUREDBUTTON_H
