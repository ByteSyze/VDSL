#include "port.h"
#include "vdsl.h"

Port::Port(QWidget *parent, QString name) : QWidget(parent)
{
    m_Label     = new QLabel();
    m_Label->setMaximumHeight(20);

    m_Connector = new Connector();

    setName(name);

    if(m_Orientation == Orientation::left)
    {
        layout.addWidget(m_Label);
        layout.addWidget(m_Connector);
    }
    else
    {
        layout.addWidget(m_Connector);
        layout.addWidget(m_Label);
    }

    this->setLayout(&layout);
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

void Port::mousePressEvent(QMouseEvent *)
{
    VDSL::selectedPort = this;
}

void Port::setName(QString name)
{
    m_Name = name;
    m_Label->setText(name);
}
