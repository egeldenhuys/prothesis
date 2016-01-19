#ifndef BUTTON_LIST_H
#define BUTTON_LIST_H

#include "ColouredButton.h"
#include <vector>
#include <QVBoxLayout>
#include <QPushButton>

using namespace std;

class button_list
{

private:
    QList<ColouredButton*> cButtonList_;

public:
    button_list(void);

    button_list(QVBoxLayout *layout, vector<std::string> *sourceNames);


    vector<std::string> *sourceList;

    QVBoxLayout *parentLayout;

    int change_colour(string name, string colour);

    void add_button(QString name, QString colour);
    int remove_button(string name);
    void remove_button(int index);
    void update();
    int exists(string name);
    void applyColour();

};

#endif // BUTTON_LIST_H
