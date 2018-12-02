#ifndef MULTIPLYFLOAT_H
#define MULTIPLYFLOAT_H

#include <Modules/module.h>
#include <Ports/floatinput.h>
#include <Ports/floatoutput.h>

class MultiplyFloat : public Module
{
    Q_OBJECT
public:
    explicit MultiplyFloat(QWidget *parent = nullptr);

    void run();

    Module *clone();

private:

    FloatInput *in1, *in2;

    FloatOutput *out;
};

#endif // MULTIPLYFLOAT_H
