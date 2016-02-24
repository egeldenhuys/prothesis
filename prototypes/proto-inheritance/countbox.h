#ifndef COUNTBOX_H
#define COUNTBOX_H

#include <QObject>
#include <QCheckBox>
#include <vector>

const int MAX_CHECKED = 2;

class countBox : public QCheckBox
{
    Q_OBJECT

private:
    static std::vector<countBox*> boxVector;
    int myNumber;


public:
    countBox(QWidget *parent);
    int countChanged(int count);

signals:
    countChangedSignal(int val);
    limitReachedSignal(bool state);
    toggleStateSignal(bool state);

public slots:
    void increaseCount(int checkState);
    void toggleState(bool state);
    void finishedSetup();


};



#endif // COUNTBOX_H
