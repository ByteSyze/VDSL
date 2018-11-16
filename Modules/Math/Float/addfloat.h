#ifndef ADDFLOAT_H
#define ADDFLOAT_H

#include <Modules/module.h>
#include <Ports/floatinput.h>
#include <Ports/floatoutput.h>

class AddFloat : public Module
{
    Q_OBJECT
public:
    explicit AddFloat(QWidget *parent = nullptr);

    void run();

private:

    FloatInput *in1, *in2;

    FloatOutput *out;

signals:

public slots:
};

#endif // ADDFLOAT_H