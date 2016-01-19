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

    static QString globalColour;

    QString colour;
    void ApplyColour(QString newColour);

private slots:
    void ApplyColourClicked();
};

#endif // COLOUREDBUTTON_H
