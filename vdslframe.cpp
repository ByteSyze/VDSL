#include "vdslframe.h"
#include "vdsl.h"
#include "Ports/port.h"
#include "Ports/output.h"
#include <QPainter>
#include <QMimeData>
#include <QDebug>

VDSLFrame::VDSLFrame(QWidget *parent) : QFrame (parent)
{
    this->setMouseTracking(true);
    this->setMinimumSize(QSize(1000,1000));

    this->setStyleSheet("background:white;");

    this->setAcceptDrops(true);
}

void VDSLFrame::run()
{
    emit tick();
}

bool VDSLFrame::isUserSelecting()
{
    return m_isUserSelecting;
}

QPoint VDSLFrame::userSelectionP1()
{
    return selectionP1;
}

QPoint VDSLFrame::userSelectionP2()
{
    return selectionP2;
}

void VDSLFrame::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        m_isUserSelecting = true;
        selectionP1 = e->pos();
    }
    else if(e->button() == Qt::MiddleButton)
    {

    }
    else if(VDSL::selectedPort != nullptr)
    {
        VDSL::selectedPort = nullptr;
        update();
    }
}

void VDSLFrame::mouseReleaseEvent(QMouseEvent *)
{
    if(isUserSelecting())
    {
        m_isUserSelecting = false;
        update();
    }
}

void VDSLFrame::mouseMoveEvent(QMouseEvent *e)
{
    if(isUserSelecting())
    {
        selectionP2 = e->pos();
        update();
    }
    else if(VDSL::selectedPort != nullptr)
    {
        update();
    }
}

void VDSLFrame::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}

void VDSLFrame::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->data("vdsl::createitem") != nullptr)
    {
        QWidget *sourceWidget = qobject_cast<QWidget *>(event->source());

        if(sourceWidget != nullptr)
        {
            sourceWidget->setParent(this);
            sourceWidget->move(event->pos());
            sourceWidget->show();
        }
    }
}
