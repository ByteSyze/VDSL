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

void Connector::mousePressEvent(QMouseEvent *)
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
}
