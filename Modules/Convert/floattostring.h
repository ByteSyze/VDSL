#ifndef FLOATTOSTRING_H
#define FLOATTOSTRING_H

#include <Modules/module.h>
#include <Ports/floatinput.h>
#include <Ports/stringoutput.h>

class FloatToString : public Module
{
    Q_OBJECT
public:
    explicit FloatToString(QWidget *parent = nullptr);

    void run();

    Module *clone();

private:

    FloatInput *in;

    StringOutput *out;

signals:

public slots:

};

#endif // FLOATTOSTRING_H
