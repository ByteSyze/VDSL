#include "stringoutput.h"

StringOutput::StringOutput(QWidget* parent) : Output(parent){}

const char *StringOutput::interface()
{
    return SIGNAL(send(QString));
}
