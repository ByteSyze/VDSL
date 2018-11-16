#ifndef INTEGEROUTPUT_H
#define INTEGEROUTPUT_H

#include "output.h"

class IntegerOutput : public Output
{
    Q_OBJECT
public:
    explicit IntegerOutput(QWidget *parent = nullptr);

protected:

    const char *interface();

signals:

    void send(int);

};

#endif // INTEGEROUTPUT_H
