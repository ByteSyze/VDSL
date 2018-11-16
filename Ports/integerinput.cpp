#include "integerinput.h"

IntegerInput::IntegerInput(QWidget *parent) : Input(parent){}

int IntegerInput::data()
{
    return m_Data;
}

const char *IntegerInput::interface()
{
    return SLOT(receive(int));
}

void IntegerInput::receive(int val)
{
    m_Data = val;
    setDataReady(true);
}
