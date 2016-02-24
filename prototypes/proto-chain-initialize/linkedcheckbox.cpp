#include "linkedcheckbox.h"

std::vector<LinkedCheckBox*> LinkedCheckBox::LinkedCheckBoxVector;

LinkedCheckBox::LinkedCheckBox(QWidget* parent)
    :QCheckBox(parent)
{

    //

    // Limit reached signal -> connect to first box in chain of same group

    // Set Check State Signal   -> connect previous box to this one if there is one of same group
    //                          -> connect to itself if the first box in the group

}


void LinkedCheckBox::handleCheckedChange(int newCheckState)
{

}


void LinkedCheckBox::setCheckable_Chain(bool checkable)
{

}

void LinkedCheckBox::initialize_Chain()
{

}

