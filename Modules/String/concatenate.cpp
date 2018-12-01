#include "concatenate.h"

Concatenate::Concatenate(QWidget *parent) : Module("Concatenate", parent)
{
    in1 = new StringInput;
    in1->setName("Input 1");

    in2 = new StringInput;
    in2->setName("Input 2");

    out = new StringOutput;
    out->setName("Output");

    registerInput(in1);
    registerInput(in2);

    registerOutput(out);
}

void Concatenate::run()
{
    out->send(in1->data() + " " + in2->data());
}

Module *Concatenate::clone()
{
    return new Concatenate;
}
