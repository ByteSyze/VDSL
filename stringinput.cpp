#include "stringinput.h"
#include <QDebug>

StringInput::StringInput(QWidget *parent) : Input(parent)
{
}

const char *StringInput::interface()
{
    return SLOT(receive(QString));
}

void StringInput::receive(QString str)
{
    qDebug() << str;
}
