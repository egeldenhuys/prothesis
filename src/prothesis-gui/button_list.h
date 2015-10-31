#ifndef BUTTON_LIST_H
#define BUTTON_LIST_H

#include "coloured_button.h"
#include <vector>
#include <QVBoxLayout>

using namespace std;

class button_list
{

public:
    button_list(QVBoxLayout *layout);

    vector<coloured_button> coloured_buttons;


    QVBoxLayout *parentLayout;

    int change_colour(string name, string colour);

    int add_button(QString name, QString colour);
    int remove_button(string name);
    int remove_button(int index);
    int update();
    int exists(string name);
    void applyColour();

};

#endif // BUTTON_LIST_H
