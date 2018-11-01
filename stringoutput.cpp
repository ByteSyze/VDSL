#include "stringoutput.h"
#include <QLineEdit>
#include <QtDebug>

StringOutput::StringOutput(QWidget* parent) : Output(parent){}

const char *StringOutput::interface()
{
    return SIGNAL(send(QString));
}
