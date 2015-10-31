#include "button_list.h"

button_list::button_list()
{

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
