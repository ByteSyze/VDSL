#include "input.h"

Input::Input(QWidget *parent, QString name) : Port(parent, name, Orientation::left){}

Port::Type Input::type() const
{
    return Port::Type::input;
}

bool Input::isConnected(Port *p)
{
    if(p->type() == Port::Type::output)
    {
        return p->isConnected(this);
    }
    else return false;
}

void Input::onConnect(Port *p){}
void Input::onDisconnect(Port *p){}
