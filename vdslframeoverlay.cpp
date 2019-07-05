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

#include "vdslframeoverlay.h"

#include "vdsl.h"

#include <QPainter>
#include <QDebug>

VDSLFrameOverlay::VDSLFrameOverlay(QWidget *parent) : QWidget(parent)
{
    this->setAttribute(Qt::WA_TransparentForMouseEvents);

    selectionBorderColor = QColor(64,210,64,200);
    selectionColor       = QColor(28,168,28,128);
}

void VDSLFrameOverlay::setFrame(VDSLFrame *frame)
{
    this->frame = frame;
}

void VDSLFrameOverlay::paintEvent(QPaintEvent *)
{
    QList<Output *> outputs = frame->findChildren<Output *>();

    QPainter painter(this);
    QBrush brush(QColor(128,128,128),Qt::BrushStyle::SolidPattern);
    QPen pen(brush,2.5,Qt::PenStyle::SolidLine,Qt::PenCapStyle::RoundCap);

    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing, true);

    /* Draw all port connections */
    for(int i = 0; i < outputs.size(); i++)
    {
        Output *output = outputs[i];
        QList<Port *> *connected = output->getConnected();

        for(int j = 0; j < connected->size(); j++)
        {
            Port *p = (*connected)[j];

            QPoint start = output->mapTo(frame,output->connectorPos());
            QPoint end   = p->mapTo(frame, p->connectorPos());

            QPoint c1(start.x()+100,start.y());
            QPoint c2(end.x()-100,end.y());

            QPainterPath path;
            path.moveTo(start);
            path.cubicTo(c1,c2,end);

            painter.drawPath(path);
        }
    }

    /* Draw a pending connection from the currently selected port to the cursor. */
    if(VDSL::selectedPort != nullptr)
    {
        Port *selected = VDSL::selectedPort;

        QPoint start = selected->mapTo(frame,selected->connectorPos());
        QPoint end   = mapFromGlobal(QCursor::pos());

        Port::Orientation o = VDSL::selectedPort->orientation();
        int dir = (o == Port::Orientation::left) ? -1 : 1;
        QPoint c1(start.x()+100*dir,start.y());
        QPoint c2(end.x()-100*dir,end.y());

        QPainterPath path;
        path.moveTo(start);
        path.cubicTo(c1,c2,end);

        pen.setStyle(Qt::PenStyle::DotLine);
        painter.setPen(pen);

        painter.drawPath(path);
    }

    if(frame->isUserSelecting())
    {
        QPoint p1 = frame->userSelectionP1();
        QPoint p2 = frame->userSelectionP2();

        QPoint topLeft, botRight;

        topLeft.setX((p1.x() < p2.x()) ? p1.x() : p2.x());
        topLeft.setY((p1.y() > p2.y()) ? p1.y() : p2.y());

        botRight.setX((p1.x() > p2.x()) ? p1.x() : p2.x());
        botRight.setY((p1.y() < p2.y()) ? p1.y() : p2.y());

        QRect selectionArea(topLeft, botRight);

        painter.setPen(selectionBorderColor);
        painter.fillRect(selectionArea, selectionColor);
        painter.drawRect(selectionArea);

    }
}
