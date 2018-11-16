#include "integeroutput.h"

IntegerOutput::IntegerOutput(QWidget *parent) : Output(parent){}

const char *IntegerOutput::interface()
{
    return SIGNAL(send(int));
}
