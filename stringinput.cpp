#include "stringinput.h"
#include <QDebug>

StringInput::StringInput(QWidget *parent) : Port(parent)
{
}

const char *StringInput::interface()
{
    return SLOT(receive(QString));
}

Port::Type StringInput::type() const
{
    return Port::Type::input;
}

void StringInput::onConnect()
{

}

void StringInput::receive(QString str)
{
    qDebug() << str;
}
