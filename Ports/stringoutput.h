#ifndef STRINGOUTPUT_H
#define STRINGOUTPUT_H

#include "output.h"

class StringOutput : public Output
{
    Q_OBJECT

public:
    explicit StringOutput(QWidget *parent = nullptr);

protected:

    const char *interface();

signals:

    void send(QString);

};

#endif // STRINGOUTPUT_H
