#include "countbox.h"
#include <string>
#include "mainwindow.h"
#include <QMessageBox>
#include <iostream>

std::vector<countBox*> countBox::boxVector;

countBox::countBox(QWidget* parent)
    :QCheckBox(parent)
{

    std::cout << "INIT: " << this->accessibleDescription().toStdString() << "\n";

    // Counter
    connect(this, &countBox::stateChanged, this, &countBox::increaseCount);

    // Record
    boxVector.push_back(this);

    myNumber = countBox::boxVector.size() -1;
    std::cout << myNumber << "\n";


    // If this is the first box, connect the limit to itself
    if (myNumber == 0)
        connect(this, &countBox::limitReachedSignal, this, &countBox::toggleState);

    // iF this is the second box do. Limit signal -> A. Toggle A -> B
    if (countBox::boxVector.size() > 1)
    {
        connect(this, &countBox::limitReachedSignal, boxVector.at(0), &countBox::toggleState);
    }

    // Connect previous toggle signal to this one
    if (countBox::boxVector.size() >= 2)
    {
        connect(boxVector.at(myNumber - 1), &countBox::toggleStateSignal, this, &countBox::toggleState);
    }

}

void countBox::increaseCount(int checkState)
{
    std::cout << this->accessibleDescription().toStdString() << "\n";

    std::cout << "increase count at " << this->objectName().toStdString() << " (" << myNumber << ")\n";
    static int counter = 0;

    // If two boxes are already selected and this on ahs just been checked
    // Show message and uncheck this one.
    //
    // If two boxes already checked and this one has just been unchecked,
    // reduce counter

    // else increase counter

    if ((counter == MAX_CHECKED - 1) && (checkState == 2))
        emit limitReachedSignal(0);
    else if ((counter == MAX_CHECKED) && (checkState == 0))
        emit limitReachedSignal(1);

    if (checkState == 0)
        counter -= 1;
    else if (checkState == 2)
        counter++;


    QString wat;
    wat = "NO " + QString::fromStdString(std::to_string(counter));

    this->setText(wat);


}

void countBox::toggleState(bool state)
{
    std::cout << "Toggle State at " << this->objectName().toStdString() << "\n";

    if (this->checkState() == 0)
    {
        this->setCheckable(state);
        this->setDisabled(!state);
    }

    emit toggleStateSignal(state);

}

void countBox::finishedSetup()
{
    std::cout << this->accessibleDescription().toStdString();
}

/* Box is checked
 * Event->
 * sees that limit is reached
 * emit signal for disabling all checkboxes that listen on a slot
*/


/* [ boxCount objects...]
 * A B C D E
 * D gets checked, emits the limit signal.
 * D (Limit Signal)-> A
 * A disables.
 * A (Limit Signal)-> B
 * B disables.
 * Repeats until E has also received signal and disabled.
 *
 * A B C D E Emits signal to slot on A.
 * A emits to slot on B
 * D (Limit)-> A (Disable)-> B (Disable)-> C (Disable)-> D (Disable)-> E
*/
