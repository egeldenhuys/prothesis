/* LinkedCheckBox.cpp
 * ================
 *
 * NOTE:
 * This is a quick hack to solve a problem that has not been planned for
 * from the start. It is quicker to use this solution than to redesign
 * large parts of the original program.
 *
 * DESCRIPTION:
 * This provides a CheckBox object that will disable itself when the maximum
 * number of check boxes in its group has been checked.
 *
 * USAGE:
 * - The "accessibleName" property is used for the group name.
 * - The "accessibleDescription" is used for the number of checkboxes that can be ticked
 *      before the rest are disabled
 *
 * EXAMPLE:
 * 1. Create some normal QCheckBox using the designer.
 * 2. Promote the QCheckBoxes to LinkedCheckBoxes
 * 3. Set the group names and max values using the information provided in the USAGE.
 *
 * let group = "A"
 * let max = 3
 *
 * When the 3rd checkbox in group A is checked,
 * all other checkboxes in the group that are not checked will
 * be disabled
*/

#include "linkedcheckbox.h"

std::vector<LinkedCheckBox*> LinkedCheckBox::linkVector;

LinkedCheckBox::LinkedCheckBox(QWidget* parent)
    :QCheckBox(parent)
{
    /* Here we set up the initialize chain
     *
     * listVector:
     * - Each object adds itself to the static vector in this constructor
     *
     * startInitialize:
     * - All connect their 'startInitialize' signal to the 'initialize' slot on the first object
     * - The first object connects it's own 'startInitialize' signal to its own 'initialize' slot
     *
     * contInitialize:
     * - The 'initialize' slot will emit the 'contInitialize' signal
     * - Each object connects the 'contInitialize' signal from the previous object to its own 'initialize' slot
     * - The first object connects nothing, as there is nothing before it
    */

    groupCount = 0;

    linkVector.push_back(this);


    myIndex = linkVector.size() - 1;

    // Connect the startInitialize signals
    if (myIndex == 0)
    {
        bool connectStatus;
        connectStatus = connect(this, &LinkedCheckBox::startInitialize, this, &LinkedCheckBox::initialize);

        // DEBUG
        std::cout << "startInitialize: [" << myIndex << "]  -> [" << myIndex << "] = " << connectStatus << "\n";

    }
    else
    {
        bool connectStatus;

        connectStatus = connect(this, &LinkedCheckBox::startInitialize, linkVector.at(0), &LinkedCheckBox::initialize);

        // DEBUG
        std::cout << "startInitialize: [" << myIndex << "]  -> [" << "0" << "] = " << connectStatus << "\n";
    }

    // Connect the contInitialize signal
    if (myIndex > 0)
    {
        bool connectStatus;
        connectStatus = connect(linkVector.at(myIndex - 1), &LinkedCheckBox::contInitialize, this, &LinkedCheckBox::initialize);
        // DEBUG
        std::cout << "contInitialize: [" << (myIndex - 1 )<< "]  -> [" << myIndex << "] = " << connectStatus << "\n";
    }

    // DEBUG
    std::cout << myIndex << ": Created.\n";

    // Connect the CheckStateChanged signal to itself
    connect(this, &LinkedCheckBox::stateChanged, this, &LinkedCheckBox::handleCheckedChange);

}

void LinkedCheckBox::handleCheckedChange(int newCheckState)
{
    // DEBUG
    std::cout << myIndex << ": newCheckState = " << newCheckState << "\n";


    // If two boxes are already selected and this on ahs just been checked
    // Show message and uncheck this one.
    //
    // If two boxes already checked and this one has just been unchecked,
    // reduce counter

    // else increase counter


    // Enable/Disable checkboxes
    if ((*hostGroupCount == groupMax - 1) && (newCheckState == 2))
    {
        // DEBUG
        std::cout << myIndex << ": max (" << groupMax << ") reached. emit startSetCheckable(0)\n";

        emit startSetCheckable(0);
    }
    else if ((*hostGroupCount == groupMax) && (newCheckState == 0))
    {
        // DEBUG
        std::cout << myIndex << ": max (" << groupMax << ") reached. emit startSetCheckable(1)\n";

        emit startSetCheckable(1);
    }

    // Increase/Decrase counter
    if (newCheckState == 0)
        *hostGroupCount = *hostGroupCount - 1;
    else if (newCheckState == 2)
       *hostGroupCount = *hostGroupCount + 1;


    // DEBUG
    std::cout << "\tcount = " << *hostGroupCount << "\n";

}


void LinkedCheckBox::setCheckable(bool checkable)
{

    // DEBUG
    std::cout << myIndex << ": checkable = " << checkable << "\n";

    // Only do something if it is not checked
    if (this->checkState() == 0)
    {
        this->setDisabled(!checkable);
    }

    // DEBUG
    std::cout << myIndex << ": emit contSetCheckable(" << checkable << ")\n";
    emit contSetCheckable(checkable);

}

void LinkedCheckBox::initialize()
{
    bool convertStatus = false;


    groupMax = this->accessibleDescription().toInt();

    // DEBUG
    std::cout << myIndex << ": initialize():\n";
    std::cout << "\taccessibleName (Group) = " << this->accessibleName().toStdString() << "\n";
    std::cout << "\taccessibleDescription (Max) = " << groupMax << " (" << convertStatus << "\n";


    /* Index: 0, 1, 2, 3, 4, 5, 6
     * Group: A, A, B, C, B, C, A
     *
     * contSetCheckable:
     * 0 sees that it is first. Does nothing.
     *
     * (1 needs to connect to 0 (prev))
     * 1 goes through and finds 0 as the first. Connects to it
     *
     * (6 needs to connect to 1)
     * 6 starts counting backwards from 5 until it finds 1
     * 6 connects 1 to itself.
    */

    /* Here we set up the setCheckable chain
     *
     * startSetCheckable:
     * - Each object connect the the first in its group
     * - The first object in the group connects to itself
     *
     * contSetCheckable:
     * - Each object connects to the previous in its group
     * - Each objects starts looking from myIndex -1, that way it finds the one previous to it
     * - The first object does nothing, as there is nothing before it
     *
     * int *hostGroupCount
     * - Here we also set the pointer to the groupCount of the first object in the group.
     * - The first object points to its own groupCount variable
     * - All other objects points to the groupCount on the host
    */


    /* startSetCheckable:
     * - Go through every element in series in the linkVector until I find an object with the same group
     * - If that object matches myIndex: connect my own 'startSetCheckable' to my own 'setCheckable' slot
     * - if not: connect my 'startSetCheckable' signal to that object's 'setCheckable slot'
    */

    // accessibleName() is used for the group name.

    // startSetCheckable

    bool foundFirst = false;

    for (int i = 0; ((i < linkVector.size()) && !foundFirst); i++)
    {
        if (linkVector.at(i)->accessibleName() == this->accessibleName())
        {
            if (i == myIndex)
            {
                bool connectStatus;
                connectStatus = connect(this, &LinkedCheckBox::startSetCheckable, this, &LinkedCheckBox::setCheckable);

                // DEBUG
                std::cout << "startSetCheckable: [" << myIndex << "]  -> [" << myIndex << "] = " << connectStatus << "\n";

                // groupCount
                hostGroupCount = &groupCount;

                foundFirst = true;
            }
            else
            {
                bool connectStatus;
                connectStatus = connect(this, &LinkedCheckBox::startSetCheckable, linkVector.at(i), &LinkedCheckBox::setCheckable);

                // DEBUG
                std::cout << "startSetCheckable: [" << myIndex << "]  -> [" << i << "] = " << connectStatus << "\n";

                // groupCount
                hostGroupCount = &linkVector.at(i)->groupCount;

                foundFirst = true;
            }
        }
    }

    // contSetCheckable
    if (myIndex > 0)
    {
        foundFirst = false;

        for (int i = (myIndex - 1); ((i >= 0) && !foundFirst); i -= 1)
        {
            if (linkVector.at(i)->accessibleName() == this->accessibleName())
            {
                bool connectStatus;
                connectStatus = connect(linkVector.at(i), &LinkedCheckBox::contSetCheckable, this, &LinkedCheckBox::setCheckable);

                // DEBUG
                std::cout << "contSetCheckable: [" << i << "]  -> [" << myIndex << "] = " << connectStatus << "\n";

                foundFirst = true;
            }
        }

    }

    // DEBUG
    std::cout << myIndex << ": emit contInitialize\n";
    emit contInitialize();

}

void LinkedCheckBox::printIndex()
{

    // Index
    std::cout << "[";

    for (int i = 0; i < linkVector.size(); i++)
    {
        std::cout << std::setw(2) << i << ",";

    }

    std::cout << "]\n";

    // Group Name
    std::cout << "[";

    for (int i = 0; i < linkVector.size(); i++)
    {
        std::cout << std::setw(2) << linkVector.at(i)->accessibleName().toStdString() << ",";

    }

    std::cout << "]\n";
}

