#include "vdslframe.h"
#include "vdsl.h"
#include "port.h"
#include <QPainter>

VDSLFrame::VDSLFrame(QWidget *parent) : QFrame (parent)
{
    this->setMouseTracking(true);
}

void VDSLFrame::paintEvent(QPaintEvent *event)
{
    if(VDSL::selectedPort != nullptr)
    {
        QPainter painter(this);
        QBrush brush(QColor(128,128,128),Qt::BrushStyle::SolidPattern);
        QPen pen(brush,2.5,Qt::PenStyle::DotLine,Qt::PenCapStyle::RoundCap);

        painter.setPen(pen);
        painter.setRenderHint(QPainter::Antialiasing, true);

        QPoint start = VDSL::selectedPort->connectorPos();
        QPoint end   = mapFromGlobal(QCursor::pos());

        Port::Orientation o = VDSL::selectedPort->orientation();
        int dir = (o == Port::Orientation::left) ? -1 : 1;
        QPoint c1(start.x()+25*dir,start.y());
        QPoint c2(end.x()-25*dir,end.y());

        QPainterPath path;
        path.moveTo(start);
        path.cubicTo(c1,c2,end);

        painter.drawPath(path);
    }
    else
    {
        QFrame::paintEvent(event);
    }
}

void VDSLFrame::mousePressEvent(QMouseEvent *event)
{
    if(VDSL::selectedPort != nullptr)
    {
        VDSL::selectedPort = nullptr;
        this->update();
    }
}

void VDSLFrame::mouseMoveEvent(QMouseEvent *event)
{
    if(VDSL::selectedPort != nullptr)
        this->update();
}
