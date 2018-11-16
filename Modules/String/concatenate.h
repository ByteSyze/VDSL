#ifndef CONCATENATE_H
#define CONCATENATE_H

#include "Modules/module.h"
#include "Ports/stringinput.h"
#include "Ports/stringoutput.h"

class Concatenate : public Module
{
    Q_OBJECT
public:
    explicit Concatenate(QWidget *parent = nullptr);

    void run();

private:

    StringInput *in1, *in2;

    StringOutput *out;

signals:

public slots:
};

#endif // CONCATENATE_H
