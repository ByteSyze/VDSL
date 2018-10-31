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
    explicit Port(QWidget *parent = nullptr, QString name = "");
    ~Port();

    enum class Orientation { left, right };

    QString name();

    QPoint connectorPos();

    Orientation orientation();

protected:

    Orientation m_Orientation = Orientation::left;

    void mousePressEvent(QMouseEvent *event) override;

private:

    void setName(QString);

    QString   m_Name;

    QHBoxLayout layout;

    Connector *m_Connector;
    QLabel    *m_Label;
};

#endif // PORT_H
