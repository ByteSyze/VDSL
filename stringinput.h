#ifndef STRINGINPUT_H
#define STRINGINPUT_H

#include "input.h"

class StringInput : public Input
{
    Q_OBJECT

public:
    explicit StringInput(QWidget *parent = nullptr);

protected:

    const char *interface();

public slots:

    void receive(QString);
};

#endif // STRINGINPUT_H
