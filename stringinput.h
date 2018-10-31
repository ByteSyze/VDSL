#ifndef STRINGINPUT_H
#define STRINGINPUT_H

#include "port.h"

class StringInput : public Port
{
    Q_OBJECT

public:
    explicit StringInput(QWidget *parent = nullptr);

protected:

    const char *interface();
    Type type() const;

    void onConnect();

public slots:

    void receive(QString);
};

#endif // STRINGINPUT_H
