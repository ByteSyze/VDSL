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

#ifndef OUTPUT_H
#define OUTPUT_H

#include "port.h"
#include <QList>

class Output : public Port
{
    Q_OBJECT
public:
    explicit Output(QWidget *parent = nullptr, QString name = "Output");
    ~Output();

    Type type() const;
    bool isConnected(Port *);

    QList<Port *> *getConnected();

private:

    QList<Port*> *connectedPorts;

protected:

    void onConnect(Port *);
    void onDisconnect(Port *);

};

#endif // OUTPUT_H
