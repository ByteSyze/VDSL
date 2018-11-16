#ifndef INTEGERINPUT_H
#define INTEGERINPUT_H

#include "input.h"

class IntegerInput : public Input
{
    Q_OBJECT
public:
    explicit IntegerInput(QWidget *parent = nullptr);

    int data();

protected:

    const char *interface();

private:

    int m_Data;

public slots:

    void receive(int);
};

#endif // INTEGERINPUT_H
