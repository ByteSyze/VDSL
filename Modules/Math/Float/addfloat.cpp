#include "addfloat.h"

AddFloat::AddFloat(QWidget *parent) : Module("Add Floats", parent)
{
    in1 = new FloatInput;
    in1->setName("Float 1");

    in2 = new FloatInput;
    in2->setName("Float 2");

    out = new FloatOutput;
    out->setName("Sum");

    registerInput(in1);
    registerInput(in2);

    registerOutput(out);
}

void AddFloat::run()
{
    out->send(in1->data() + in2->data());
}
