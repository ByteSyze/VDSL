#include "vdslframe.h"
#include "vdsl.h"
#include "port.h"
#include <QPainter>

VDSLFrame::VDSLFrame(QWidget *parent) : QFrame (parent){}

void VDSLFrame::paintEvent(QPaintEvent *event)
{
    if(VDSL::selectedPort != nullptr)
    {
        QPainter painter(this);

        QPoint start = VDSL::selectedPort->connectorPos();
        QPoint end   = mapFromGlobal(QCursor::pos());

        Port::Orientation o = VDSL::selectedPort->orientation();
        int dir = (o == Port::Orientation::left) ? 1 : -1;
        QPoint c1(start.x()+20*dir,start.y());
        QPoint c2(end.x()-20*dir,end.y());

        QPainterPath path;
        path.moveTo(start);
        path.cubicTo(c1,c2,end);

        painter.drawPath(path);
    }
}

void VDSLFrame::mouseMoveEvent(QMouseEvent *event)
{
    if(VDSL::selectedPort != nullptr)
        this->update();
}

void VDSLFrame::mousePressEvent(QMouseEvent *event)
{

}
