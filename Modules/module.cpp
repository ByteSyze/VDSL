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

#include "module.h"

#include <QDebug>

Module::Module(QString name, QWidget *parent, Module::ModuleType type) : QFrame(parent)
{
    inputs  = new QList<Input *>;
    outputs = new QList<Output *>;

    mainLayout    = new QHBoxLayout;
    contentLayout = new QVBoxLayout;

    inputLayout  = new QVBoxLayout;
    outputLayout = new QVBoxLayout;

    m_Name = name;

    m_Type = type;

    moduleLabel  = new QLabel(name);
    moduleLabel->setAlignment(Qt::AlignHCenter);

    contentLayout->addWidget(moduleLabel);

    mainLayout->setSizeConstraint(QLayout::SetMinimumSize);

    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(contentLayout);
    mainLayout->addLayout(outputLayout);

    setFrameStyle(QFrame::Panel | QFrame::Plain);

    setLayout(mainLayout);
}

Module::~Module()
{
    disconnectInputs();
    disconnectOutputs();

    moduleLabel->deleteLater();

    mainLayout->deleteLater();
    inputLayout->deleteLater();
    outputLayout->deleteLater();

    delete inputs;
    delete outputs;
}

void Module::invalidate()
{
    QList<Input*>::Iterator it;

    for(it = inputs->begin(); it != inputs->end(); it++)
    {
        (*it)->invalidateData();
    }
}

QString Module::name()
{
    return m_Name;
}

Module::ModuleType Module::type()
{
    return m_Type;
}

void Module::registerInput(Input *input)
{
    if(!inputs->contains(input))
    {
        inputs->append(input);

        inputLayout->addWidget(input);
        inputLayout->setAlignment(input, Qt::AlignVCenter);

        connect(input, SIGNAL(dataReady()), this, SLOT(onDataReady()));
    }
}

void Module::unregisterInput(Input *input)
{
    if(inputs->contains(input))
    {
        inputs->removeOne(input);
        inputLayout->removeWidget(input);

        disconnect(input, SIGNAL(dataReady(Input*)), this, SLOT(onDataReady(Input*)));
    }
}

void Module::registerOutput(Output *output)
{
    if(!outputs->contains(output))
    {
        outputs->append(output);

        outputLayout->addWidget(output);
        outputLayout->setAlignment(output, Qt::AlignVCenter);
    }
}

void Module::unregisterOutput(Output *output)
{
    outputs->removeOne(output);
    outputLayout->removeWidget(output);
}

void Module::disconnectInputs()
{
    QList<Input *>::iterator it;

    for(it = inputs->begin(); it != inputs->end(); it++)
    {
        (*it)->disconnect();
    }
}


void Module::disconnectOutputs()
{
    QList<Output *>::iterator it;

    for(it = outputs->begin(); it != outputs->end(); it++)
    {
        (*it)->disconnect();
    }
}

void Module::mouseMoveEvent(QMouseEvent *)
{
    if(isBeingDragged)
    {
        QWidget *p = static_cast<QWidget *>(parent());

        QPoint point = p->mapFromGlobal(QCursor::pos());
        move(point);

        p->update();
    }
}

void Module::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::RightButton)
        isBeingDragged = true;
}

void Module::mouseReleaseEvent(QMouseEvent *)
{
    isBeingDragged = false;
}

void Module::onDataReady()
{
    QList<Input*>::Iterator it;
    bool allDataReady = true;

    for(it = inputs->begin(); it != inputs->end(); it++)
    {
        if(!(*it)->isDataReady())
        {
            allDataReady = false;
            break;
        }
    }

    if(allDataReady)
    {
        run();
    }
}
