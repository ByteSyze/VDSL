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

#ifndef INPUT_H
#define INPUT_H

#include "port.h"

class Input : public Port
{
    Q_OBJECT
public:
    explicit Input(QWidget *parent = nullptr, QString name = "Input");

    Type type() const;
    bool isConnected(Port *); //NOTE: inputs should only have one connection at a time.

    bool isDataReady();
    void invalidateData();

protected:

    void setDataReady(bool);

    void onConnect(Port *);
    void onDisconnect(Port *);

    bool allowConnection(Port *);

private:

    Port *connectedPort = nullptr;

    bool m_DataReady = false;

signals:

    void dataReady(void);

};

#endif // INPUT_H
