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
    delete inputs;
    delete outputs;

    moduleLabel->deleteLater();

    mainLayout->deleteLater();
    inputLayout->deleteLater();
    outputLayout->deleteLater();
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

        connect(input,SIGNAL(dataReady()),this,SLOT(onDataReady()));
    }
}

void Module::unregisterInput(Input *input)
{
    if(inputs->contains(input))
    {
        inputs->removeOne(input);
        inputLayout->removeWidget(input);

        disconnect(input,SIGNAL(dataReady(Input*)),this,SLOT(onDataReady(Input*)));
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
        //if((*it) == QObject::sender())
        //    continue;

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
