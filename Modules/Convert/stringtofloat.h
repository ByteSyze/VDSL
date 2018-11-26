#ifndef STRINGTOFLOAT_H
#define STRINGTOFLOAT_H


#include <Modules/module.h>
#include <Ports/stringinput.h>
#include <Ports/floatoutput.h>

class StringToFloat : public Module
{
    Q_OBJECT
public:
    explicit StringToFloat(QWidget *parent = nullptr);

    void run();

private:

    StringInput *in;

    FloatOutput *out;

signals:

public slots:

};

#endif // STRINGTOFLOAT_H
