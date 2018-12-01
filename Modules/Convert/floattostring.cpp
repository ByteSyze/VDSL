#include "floattostring.h"

FloatToString::FloatToString(QWidget *parent) : Module("Float To String", parent)
{
    in = new FloatInput;
    in->setName("Float");

    out = new StringOutput;
    out->setName("String");

    registerInput(in);

    registerOutput(out);
}

void FloatToString::run()
{
    out->send(QString::number(in->data()));
}

Module *FloatToString::clone()
{
    return new FloatToString;
}
