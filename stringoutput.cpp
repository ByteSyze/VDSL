#include "stringoutput.h"
#include <QLineEdit>
#include <QtDebug>

StringOutput::StringOutput(QWidget* parent) : Port(parent, "", Orientation::right)
{
    connect(this,SIGNAL(connected(Port*)),this,SLOT(onConnect(Port*)));
}

const char *StringOutput::interface()
{
    return SIGNAL(send(QString));
}

Port::Type StringOutput::type() const
{
    return Port::Type::output;
}

void StringOutput::onConnect()
{
    qDebug() << "connected";
    emit send("Hello World");
}

void StringOutput::onConnect(Port *p)
{
    qDebug() << "test";
    emit send("Hello World");
}
