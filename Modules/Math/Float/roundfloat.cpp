#include "roundfloat.h"

RoundFloat::RoundFloat(QWidget *parent) : Module("Round Float", parent)
{
    in = new FloatInput;
    in->setName("Input");

    out = new FloatOutput;
    out->setName("Output");

    registerInput(in);

    registerOutput(out);
}

void RoundFloat::run()
{
    out->send(round(in->data()));
}

Module *RoundFloat::clone()
{
    return new RoundFloat;
}
