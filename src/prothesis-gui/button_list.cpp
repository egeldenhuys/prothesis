#include "button_list.h"
#include <QCoreApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "coloured_button.h"
#include <QPushButton>


button_list::button_list(void)
{


}

button_list::button_list(QVBoxLayout *layout, vector<string> *sourceNames)
{
    parentLayout = layout;
    sourceList = sourceNames;
    update();
}


/* int button_list::add_button(string name, string colour)
 * ===========================
 * Description:
 * -----------
 * Create a new button with the given name and colour.
 * This button is then added to the parent widget
 *
*/
int button_list::add_button(QString name, QString colour)
{
    // Create


    // Create new coloured button
    coloured_button *myButton = new coloured_button;
    myButton->setText(name);
    myButton->setColour(colour);

    // Add the coloured button to the vector

    coloured_buttons.push_back(*myButton);

    // Add to widget
    parentLayout->addWidget(myButton->button,0,0);

    // Connect button to function

}

void button_list::applyColour()
{
    /*
    QPushButton *theButton = qobject_cast<QPushButton*>(sender());
       if (!theButton)
          return;

    theButton->setText("YOU CLICKED ME!" + rand() % 1000);
    */
}


int button_list::remove_button(string name)
{

}

int button_list::remove_button(int index)
{
    parentLayout->removeWidget(coloured_buttons.at(index).button);
    delete coloured_buttons.at(index).button;
    coloured_buttons.erase(coloured_buttons.begin()+index);
}

/* 3. Update
* ---------
* 1. Loop through each item in UserData
* 2. If the item does not exist, create the button in the list. [Exists], [Add Button]
*
* 3. Loop through each item in the list, if it does not exist in UserData, remove it.
*/

int button_list::update()
{
    // Loop through each item in UserData
    for (uint i = 0; i < sourceList->size(); i++)
    {
        // If the item does not exist in the button list create it
        if (! exists(sourceList->at(i)))
        {
            add_button(QString::fromStdString(sourceList->at(i)), "");
        }
    }

    bool found = false;
    uint loopsDone = 0;
    uint initialSize = coloured_buttons.size();

    // Loop through every button
    for (uint i = 0; loopsDone < initialSize; i++)
    {
        // We do this because the button has been popped from the array
        // and we need to account for this

        if ((found == false) && (loopsDone >= 1))
            i = i -1;

        found = false;

        // If the button does not exist in the source list, remove the button
        for (uint j = 0; j < sourceList->size(); j++)
        {
            if (QString::fromStdString(sourceList->at(j)) == coloured_buttons.at(i).name)
            {
                found = true;
                break;
            }
        }

        if (found == false)
            remove_button(i);

        loopsDone++;

    }

}

int button_list::exists(string name)
{
    // Go through all buttons in list

    int result = 0;

    for (uint i = 0; i < coloured_buttons.size(); i++)
    {
        if (coloured_buttons.at(i).name == QString::fromStdString(name))
        {
            result = 1;
            return result;
        }
    }

    return result;
}

/* button_list
 *
 * This class manages a list of buttons.
 * Will be used for displaying the checked roles.
 *
 * Objects
 * =======
 * cButton (Coloured button)
 *      - Button Name
 *      - Button Colour
 *
 * Variables
 * =========
 *
 * - buttonNames (vector)
 * - buttonColours (vector)
 *
 * Functions
 * =========
 *
 * - Add button (name, colour)
 * - Remove button (name | index)
 * - Exists (name)
 * - Update
 *
 * Algorithms
 * ==========
 *
 * 0. Integration
 * --------------
 * User checks a checkbox
 *
 * 1. Add button ("leader", "255, 255, 0")
 * --------------
 * Loop through all buttons in vector, if name already exists, return false and exit
 * Create a new button
 * set the name to "leader"
 * set the colour to "255, 255, 0" using stylesheet
 * Add the button to the vector
 * Add the button the the parent widget
 *
 * 2. Remove button ("leader")
 * ----------------
 * Loop through the vector until button named "leader" is found
 * Remove button from the parent widget
 * Remove button from vector
 * If found, return true
 * else return false.
 *
 * 3. Update
 * ---------
 * Loop through each item in UserData
 * If the item does not exist, create the button in the list. [Exists], [Add Button]
 *
 * Loop through each item in the list, if it does not exist in UserData, remove it.
 *
*/
