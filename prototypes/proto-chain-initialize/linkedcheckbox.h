#ifndef LINKEDCHECKBOX_H
#define LINKEDCHECKBOX_H
#include <QCheckBox>
#include <vector>

class LinkedCheckBox : public QCheckBox
{
    Q_OBJECT

public:
    LinkedCheckBox(QWidget *parent);

private:
    std::vector<LinkedCheckBox*> linkedCheckBoxVector;

signals:
    startInitialize_Chain();
    contInitialize_Chain();

    startChangeCheckable_Chain(bool checkable);
    changeCheckable_Chain(bool checkable);

public slots:
    void handleCheckedChange(int newCheckState);

    void setCheckable_Chain(bool checkable);
    void initialize_Chain();


};

#endif // LINKEDCHECKBOX_H
