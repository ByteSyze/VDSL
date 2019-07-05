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

#ifndef PORT_H
#define PORT_H

#include "connector.h"

#include <QLabel>
#include <QLayout>
#include <QWidget>

/*
    An I/O port for a Transceiver.

    This class only handles the visual aspect of a data port. The Input
    and Output subclasses handle the actual transfer of data between Ports.
*/
class Port : public QWidget
{
    Q_OBJECT
public:

    enum class Orientation { left, right };
    enum class Type { input, output };

    explicit Port(QWidget *parent = nullptr, QString name = "", Orientation orientation = Orientation::left);
    ~Port();

    QString name();
    void setName(QString);

    QPoint connectorPos();

    Orientation orientation();

    bool connectTo(Port *port);
    bool disconnectFrom(Port *port);

    virtual Type type() const = 0;
    virtual bool isConnected(Port *) = 0;

protected:

    virtual const char* interface() = 0;

    virtual void onConnect(Port *) = 0;
    virtual void onDisconnect(Port *) = 0;

    virtual bool allowConnection(Port *);

    Orientation m_Orientation;

signals:

    void connectionEstablished(Port *);

private slots:

    void onConnectorClicked(void);

private:

    QString   m_Name;

    QHBoxLayout layout;

    Connector *m_Connector;
    QLabel    *m_Label;

};

#endif // PORT_H
