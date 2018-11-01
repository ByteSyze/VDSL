#include "output.h"

Output::Output(QWidget *parent, QString name) : Port(parent, name, Orientation::right)
{
    connectedPorts = new QList<Port*>();
}

Output::~Output()
{
    delete connectedPorts;
}

Port::Type Output::type() const
{
    return Port::Type::output;
}

void Output::onConnect(Port *p)
{
    connectedPorts->append(p);
}

void Output::onDisconnect(Port *p)
{
    connectedPorts->removeOne(p);
}

bool Output::isConnected(Port *p)
{
    return connectedPorts->contains(p);
}

QList<Port *> *Output::getConnected()
{
    return connectedPorts;
}
