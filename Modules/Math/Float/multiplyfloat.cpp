#include "multiplyfloat.h"

MultiplyFloat::MultiplyFloat(QWidget *parent) : Module("Multiply Float", parent)
{
    in1 = new FloatInput;
    in1->setName("Float 1");

    in2 = new FloatInput;
    in2->setName("Float 2");

    out = new FloatOutput;
    out->setName("Product");

    registerInput(in1);
    registerInput(in2);

    registerOutput(out);
}

void MultiplyFloat::run()
{
    out->send(in1->data() * in2->data());
}

Module *MultiplyFloat::clone()
{
    return new MultiplyFloat;
}
