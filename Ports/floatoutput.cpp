#include "floatoutput.h"

FloatOutput::FloatOutput(QWidget *parent) : Output(parent){}

const char *FloatOutput::interface()
{
    return SIGNAL(send(float));
}

