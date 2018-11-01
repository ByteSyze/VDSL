#include "connector.h"
#include<QPainter>

Connector::Connector(QWidget *parent) : QWidget(parent)
{
    m_Border = QRectF(0,0,10,10);
    m_Center = QRectF(1,1,8,8);

    setCursor(Qt::PointingHandCursor);
}

void Connector::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    QPen pen(Qt::PenStyle::NoPen);
    painter.setPen(pen);

    painter.setBrush(QColor(255,200,0));
    painter.drawEllipse(m_Border);

    QRadialGradient centerGrad(4.5,4.5,4.5);
    centerGrad.setColorAt(0, Qt::yellow);
    centerGrad.setColorAt(1, Qt::red);

    QBrush b(centerGrad);

    painter.setBrush(b);
    painter.drawEllipse(m_Center);
}

void Connector::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}

QSize Connector::minimumSizeHint() const
{
    return QSize(m_Border.width()+1,m_Border.height()+1);
}

QSize Connector::sizeHint() const
{
    return minimumSizeHint();
    //return QSize(m_Border.width()+1,m_Border.height()+1);
}
