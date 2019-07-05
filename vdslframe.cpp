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

    this->setStyleSheet("VDSLFrame{ background:black; } Module{ background:white; }");

    this->setAcceptDrops(true);
}

void VDSLFrame::run()
{
    invalidateModules();

    emit tick();
}

void VDSLFrame::invalidateModules()
{
    QList<Module *> modules = findChildren<Module *>();
    QList<Module *>::iterator it;

    for(it = modules.begin(); it != modules.end(); it++)
    {
        (*it)->invalidate();
    }
}

bool VDSLFrame::isUserSelecting()
{
    return m_IsUserSelecting;
}

bool VDSLFrame::isUserDragging()
{
    return m_IsUserDragging;
}

void VDSLFrame::selectModules(QRect bounds)
{
    deselectModules();

    QList<Module *> modules = findChildren<Module *>();
    QList<Module *>::iterator it;

    for(it = modules.begin(); it != modules.end(); it++)
    {
        if(bounds.contains((*it)->geometry().center()))
        {
            (*it)->setStyleSheet("color:rgb(64, 210, 64)");
            VDSL::selectedModules->append(*it);
        }
    }
}

void VDSLFrame::deselectModules()
{
    QList<Module *>::iterator it;

    for(it = VDSL::selectedModules->begin(); it != VDSL::selectedModules->end(); it++)
    {
        (*it)->setStyleSheet("color:#000000");
    }

    VDSL::selectedModules->clear();
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
    if(e->button() == Qt::RightButton)
    {
        if(isUserSelecting())
        {
             // Cancel selection
            m_IsUserSelecting = false;
            selectionP1 = selectionP2;
        }
        else
        {
            m_IsUserDragging = true;
            dragAnchor = e->pos();
        }
    }
    if(e->button() == Qt::LeftButton)
    {
        m_IsUserSelecting = true;
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

void VDSLFrame::mouseReleaseEvent(QMouseEvent *e)
{
    if(isUserSelecting())
    {
        m_IsUserSelecting = false;

        QPoint topLeft, botRight;

        topLeft.setX((selectionP1.x() < selectionP2.x()) ? selectionP1.x() : selectionP2.x());
        topLeft.setY((selectionP1.y() > selectionP2.y()) ? selectionP1.y() : selectionP2.y());

        botRight.setX((selectionP1.x() > selectionP2.x()) ? selectionP1.x() : selectionP2.x());
        botRight.setY((selectionP1.y() < selectionP2.y()) ? selectionP1.y() : selectionP2.y());

        selectModules(QRect(topLeft, botRight));
    }
    else if(isUserDragging())
    {
        m_IsUserDragging = false;
    }
    else
    {
        deselectModules();
    }

    update();
}

void VDSLFrame::mouseMoveEvent(QMouseEvent *e)
{
    if(isUserSelecting())
    {
        selectionP2 = e->pos();
        update();
    }
    else if(isUserDragging())
    {
        QList<Module *>::iterator it;

        for(it = VDSL::selectedModules->begin(); it != VDSL::selectedModules->end(); it++)
        {
            (*it)->move((*it)->pos() + (e->pos() - dragAnchor));
        }

        dragAnchor = mapFromGlobal(QCursor::pos());
        update();
    }
    else if(VDSL::selectedPort != nullptr)
    {
        update();
    }
}

void VDSLFrame::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->data("vdsl::createitem") != nullptr)
    {
        event->acceptProposedAction();
    }
}

void VDSLFrame::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->data("vdsl::createitem") != nullptr)
    {
        Module *sourceModule = qobject_cast<Module *>(event->source());

        if(sourceModule != nullptr)
        {
            if(sourceModule->type() == Module::ModuleType::emitter)
            {
                connect(this, SIGNAL(tick()), sourceModule, SLOT(onDataReady()));
            }

            sourceModule->setParent(this);
            sourceModule->move(event->pos());
            sourceModule->show();
        }
    }
}
