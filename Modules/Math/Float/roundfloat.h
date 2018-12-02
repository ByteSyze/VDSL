#ifndef ROUNDFLOAT_H
#define ROUNDFLOAT_H

#include <Modules/module.h>
#include <Ports/floatinput.h>
#include <Ports/floatoutput.h>

class RoundFloat : public Module
{
    Q_OBJECT
public:
    explicit RoundFloat(QWidget *parent = nullptr);

    void run();

    Module *clone();

private:

    FloatInput *in;

    FloatOutput *out;
};


#endif // ROUNDFLOAT_H
