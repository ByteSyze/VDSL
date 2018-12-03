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
