#include "vdslframe.h"
#include "vdsl.h"
#include "port.h"
#include "output.h"
#include <QPainter>
#include <QDebug>

VDSLFrame::VDSLFrame(QWidget *parent) : QFrame (parent)
{
    this->setMouseTracking(true);
    this->setMinimumSize(QSize(1000,1000));

    this->setStyleSheet("background:white;");
}

void VDSLFrame::run()
{
    emit tick();
}

void VDSLFrame::paintEvent(QPaintEvent *event)
{
    QList<Output *> outputs = findChildren<Output *>();

    QPainter painter(this);
    QBrush brush(QColor(128,128,128),Qt::BrushStyle::SolidPattern);
    QPen pen(brush,2.5,Qt::PenStyle::SolidLine,Qt::PenCapStyle::RoundCap);

    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing, true);

    for(int i = 0; i < outputs.size(); i++)
    {
        Output *output = outputs[i];
        QList<Port *> *connected = output->getConnected();

        for(int j = 0; j < connected->size(); j++)
        {
            Port *p = (*connected)[j];

            QPoint start = output->mapTo(this,output->connectorPos());
            QPoint end   = p->mapTo(this, p->connectorPos());

            QPoint c1(start.x()+100,start.y());
            QPoint c2(end.x()-100,end.y());

            QPainterPath path;
            path.moveTo(start);
            path.cubicTo(c1,c2,end);

            painter.drawPath(path);
        }
    }
    if(VDSL::selectedPort != nullptr)
    {
        Port *selected = VDSL::selectedPort;

        QPoint start = selected->mapTo(this,selected->connectorPos());
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
    else
    {
        QFrame::paintEvent(event);
    }
}

void VDSLFrame::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::MiddleButton)
    {
        //this->
    }
    if(VDSL::selectedPort != nullptr)
    {
        VDSL::selectedPort = nullptr;
        this->update();
    }
}

void VDSLFrame::mouseMoveEvent(QMouseEvent *)
{

    if(VDSL::selectedPort != nullptr)
        this->update();
}
