#include "modulewidget.h"
#include "stringinput.h"
#include "stringoutput.h"

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
}

void ModuleWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(isBeingDragged)
    {
        QWidget *p = static_cast<QWidget *>(parent());

        QPoint point = p->mapFromGlobal(QCursor::pos());
        move(point);

        p->update();
    }
}

void ModuleWidget::mousePressEvent(QMouseEvent *event)
{
    isBeingDragged = true;
}

void ModuleWidget::mouseReleaseEvent(QMouseEvent *event)
{
    isBeingDragged = false;
}
