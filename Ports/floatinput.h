#ifndef FLOATINPUT_H
#define FLOATINPUT_H

#include "input.h"

class FloatInput : public Input
{
    Q_OBJECT
public:
    explicit FloatInput(QWidget *parent = nullptr);

    float data();

protected:

    const char *interface();

private:

    float m_Data;

public slots:

    void receive(float);
};

#endif // FLOATINPUT_H
