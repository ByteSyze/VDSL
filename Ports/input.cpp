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

void Input::setDataReady(bool ready)
{
    m_DataReady = ready;

    if(ready == true)
        emit dataReady();
}

bool Input::isDataReady()
{
    return m_DataReady;
}

void Input::invalidateData()
{
    setDataReady(false);
}

void Input::onConnect(Port *port)
{
    connectedPort = port;
}

void Input::onDisconnect(Port *port)
{
    connectedPort = nullptr;
}

bool Input::allowConnection(Port *)
{
    return (connectedPort == nullptr); //Allow only one connection at a time.
}
