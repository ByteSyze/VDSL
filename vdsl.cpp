#include "vdsl.h"
#include "ui_vdsl.h"

#include "vdslframe.h"

#include "modulewidget.h"
#include "stringoutput.h"
#include "stringinput.h"
#include <QPainter>

Port* VDSL::selectedPort = nullptr;

VDSL::VDSL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VDSL)
{
    ui->setupUi(this);

    /*Port *output = new StringOutput();
    output->setName("Output");

    Port *input = new StringInput();
    input->setName("Input 1");
    input->move(100,100);
    Port *input2 = new StringInput();
    input2->setName("Input 2");
    input2->move(100,200);*/

    ModuleWidget *w1 = new ModuleWidget;
    ModuleWidget *w2 = new ModuleWidget;
    ModuleWidget *w3 = new ModuleWidget;
    ModuleWidget *w4 = new ModuleWidget;

    //ui->verticalLayout->addWidget(p);
    VDSLFrame *frame = new VDSLFrame;
    ui->scrollArea->setWidget(frame);

    //output->setParent(frame);
    //input->setParent(frame);
    //input2->setParent(frame);
    w1->setParent(frame);
    w2->setParent(frame);
    w3->setParent(frame);
    w4->setParent(frame);
}

VDSL::~VDSL()
{
    delete ui;
}
