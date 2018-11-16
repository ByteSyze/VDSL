#ifndef FLOATOUTPUT_H
#define FLOATOUTPUT_H

#include "output.h"

class FloatOutput : public Output
{
    Q_OBJECT
public:
    explicit FloatOutput(QWidget *parent = nullptr);

protected:

    const char *interface();

signals:

    void send(float);

};

#endif // FLOATOUTPUT_H
