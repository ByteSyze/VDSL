/*
    Copyright (C) 2018-2019 Tyler Hackett

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "port.h"
#include "vdsl.h"
#include <QDebug>

Port::Port(QWidget *parent, QString name, Orientation orientation) : QWidget(parent)
{
    m_Label     = new QLabel();
    m_Connector = new Connector();

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
    }

    return successful;
}

bool Port::disconnectFrom(Port *port)
{
    bool successful = false;

    if(port->type() == this->type())
        return successful;
    if(!port->isConnected(this))
        return successful;

    if(this->type() == Type::input)
    {
        successful = disconnect(port, port->interface(), this, this->interface());
    }
    else
    {
        successful = disconnect(this, this->interface(), port, port->interface());
    }

    if(successful)
    {
        this->onDisconnect(port);
        port->onDisconnect(this);
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
        bool success;

        if(this->isConnected(VDSL::selectedPort))
        {
            qDebug() << "is connected";
            success = disconnectFrom(VDSL::selectedPort);
        }
        else
        {
            success = connectTo(VDSL::selectedPort);
        }

        qDebug() << success;
    }
}

void Port::setName(QString name)
{
    m_Name = name;
    m_Label->setText(name);
}
