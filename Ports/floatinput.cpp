#include "floatinput.h"

FloatInput::FloatInput(QWidget *parent) : Input(parent){}

float FloatInput::data()
{
    return m_Data;
}

const char *FloatInput::interface()
{
    return SLOT(receive(float));
}

void FloatInput::receive(float val)
{
    m_Data = val;
    setDataReady(true);
}
