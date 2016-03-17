#ifndef LINKEDCHECKBOX_H
#define LINKEDCHECKBOX_H

#include <QCheckBox>
#include <vector>
#include <iostream>
#include <iomanip>

class LinkedCheckBox : public QCheckBox
{
    Q_OBJECT

public:
    LinkedCheckBox(QWidget *parent);

    void printIndex();

private:
    static std::vector<LinkedCheckBox*> linkVector;
    int groupCount;
    int groupMax;
    int myIndex;

    int *hostGroupCount;

signals:
    void startInitialize();
    void contInitialize();

    void startSetCheckable(bool checkable);
    void contSetCheckable(bool checkable);

public slots:
    void handleCheckedChange(int newCheckState);
    void setCheckable(bool checkable);
    void initialize();

};

#endif // LINKEDCHECKBOX_H
