#include "stringinput.h"
#include <QDebug>

StringInput::StringInput(QWidget *parent) : Input(parent)
{
}

QString StringInput::data()
{
    return m_Data;
}

const char *StringInput::interface()
{
    return SLOT(receive(QString));
}

void StringInput::receive(QString str)
{
    m_Data = str;
    setDataReady(true);
}
