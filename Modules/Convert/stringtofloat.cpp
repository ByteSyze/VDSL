#include "stringtofloat.h"

StringToFloat::StringToFloat(QWidget *parent) : Module("String To Float", parent)
{
    in = new StringInput;
    in->setName("String");

    out = new FloatOutput;
    out->setName("Float");

    registerInput(in);

    registerOutput(out);
}

void StringToFloat::run()
{
    out->send(in->data().toFloat());
}
