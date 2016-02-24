#include "countboxmanager.h"

CountBoxManager::CountBoxManager(QObject *parent) : QObject(parent)
{

}

/* Checkbox state is changed. Event ->
 * if count is less than seven continue, else messagebox and uncheck that checkbox.
 *
*/
