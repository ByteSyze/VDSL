#ifndef STRINGINPUTFIELD_H
#define STRINGINPUTFIELD_H

#include "Modules/module.h"
#include "Ports/stringoutput.h"
#include <QLineEdit>

class StringInputField : public Module
{
    Q_OBJECT
public:
    explicit StringInputField(QWidget *parent = nullptr);

    void run();

    Module *clone();

private:

    StringOutput *out;

    QLineEdit *inputField;

signals:

public slots:
};

#endif // STRINGINPUTFIELD_H
