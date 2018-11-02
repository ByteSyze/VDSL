#ifndef STRINGINPUT_H
#define STRINGINPUT_H

#include "input.h"

class StringInput : public Input
{
    Q_OBJECT

public:
    explicit StringInput(QWidget *parent = nullptr);

    QString data();

protected:

    const char *interface();

private:

    QString m_Data;

public slots:

    void receive(QString);
};

#endif // STRINGINPUT_H
