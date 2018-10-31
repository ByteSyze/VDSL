#ifndef INPUT_H
#define INPUT_H

#include "port.h"

class Input : public Port
{
    Q_OBJECT
public:
    explicit Input(QWidget *parent = nullptr);

    virtual const char* getInputSlot() = 0;
};

#endif // INPUT_H
