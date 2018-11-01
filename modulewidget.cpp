#include "modulewidget.h"
#include "stringinput.h"
#include "stringoutput.h"

#include <QDebug>

ModuleWidget::ModuleWidget(QWidget *parent) : QFrame(parent)
{
    inputs  = new QList<Input *>;
    outputs = new QList<Output *>;

    mainLayout   = new QHBoxLayout;
    inputLayout  = new QVBoxLayout;
    outputLayout = new QVBoxLayout;

    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(outputLayout);

    setStyleSheet("background:gray;");
    setFrameStyle(QFrame::Panel | QFrame::Plain);

    setLayout(mainLayout);
}

ModuleWidget::~ModuleWidget()
{
    delete inputs;
    delete outputs;

    mainLayout->deleteLater();
    inputLayout->deleteLater();
    outputLayout->deleteLater();
}

void ModuleWidget::registerInput(Input *input)
{
    if(!inputs->contains(input))
    {
        inputs->append(input);
        connect(input,SIGNAL(dataReady(Input*)),this,SLOT(onDataReady(Input*)));
    }
}

void ModuleWidget::unregisterInput(Input *input)
{
    if(inputs->contains(input))
    {
        inputs->removeOne(input);
        disconnect(input,SIGNAL(dataReady(Input*)),this,SLOT(onDataReady(Input*)));
    }
}

void ModuleWidget::registerOutput(Output *output)
{
    if(!outputs->contains(output))
    {
        outputs->append(output);
    }
}

void ModuleWidget::unregisterOutput(Output *output)
{
    outputs->removeOne(output);
}

void ModuleWidget::mouseMoveEvent(QMouseEvent *)
{
    if(isBeingDragged)
    {
        QWidget *p = static_cast<QWidget *>(parent());

        QPoint point = p->mapFromGlobal(QCursor::pos());
        move(point);

        p->update();
    }
}

void ModuleWidget::mousePressEvent(QMouseEvent *)
{
    isBeingDragged = true;
}

void ModuleWidget::mouseReleaseEvent(QMouseEvent *)
{
    isBeingDragged = false;
}

void ModuleWidget::performAction()
{
    qDebug() << "Let's do something!";
}

void ModuleWidget::onDataReady()
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
        performAction();
    }
}
