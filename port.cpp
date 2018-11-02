#include "port.h"
#include "vdsl.h"
#include <QDebug>

Port::Port(QWidget *parent, QString name, Orientation orientation) : QWidget(parent)
{
    m_Label     = new QLabel();
    m_Connector = new Connector();

    //this->setMaximumHeight(30);
    setName(name);

    m_Orientation = orientation;

    if(orientation == Orientation::left)
    {
        layout.addWidget(m_Connector);
        layout.addWidget(m_Label);
    }
    else
    {
        layout.addWidget(m_Label);
        layout.addWidget(m_Connector);
    }

    this->setLayout(&layout);

    connect(m_Connector, SIGNAL(clicked()), this, SLOT(onConnectorClicked()));
}

Port::~Port()
{
    m_Label->deleteLater();
    m_Connector->deleteLater();
}

QPoint Port::connectorPos()
{
    return m_Connector->pos()+QPoint(5,5);
}

Port::Orientation Port::orientation()
{
    return m_Orientation;
}

bool Port::connectTo(Port *port)
{
    bool successful = false;

    if(port->type() == this->type())
        return successful;
    if(port->isConnected(this))
        return successful;
    if(this->allowConnection(port) == false || port->allowConnection(this) == false)
        return successful;

    if(this->type() == Type::input)
    {
        successful = connect(port, port->interface(), this, this->interface());
    }
    else
    {
        successful = connect(this, this->interface(), port, port->interface());
    }

    if(successful)
    {
        this->onConnect(port);
        port->onConnect(this);

        //TODO emit connection signal and remove onConnect()
    }

    return successful;
}

bool Port::allowConnection(Port *)
{
    return true;
}

void Port::onConnectorClicked()
{
    if(VDSL::selectedPort == nullptr)
    {
        VDSL::selectedPort = this;
    }
    else
    {
        bool success = connectTo(VDSL::selectedPort);

        qDebug() << success;
    }
}

void Port::setName(QString name)
{
    m_Name = name;
    m_Label->setText(name);
}
