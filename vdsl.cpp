#include "vdsl.h"
#include "ui_vdsl.h"
#include "vdslframe.h"
#include "port.h"
#include "stringoutput.h"
#include "stringinput.h"
#include <QPainter>

Port* VDSL::selectedPort = nullptr;

VDSL::VDSL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VDSL)
{
    ui->setupUi(this);

    Port *output = new StringOutput();
    output->setName("Output");

    Port *input = new StringInput();
    input->setName("Input");
    input->move(100,100);

    //ui->verticalLayout->addWidget(p);
    VDSLFrame *frame = new VDSLFrame;
    ui->scrollArea->setWidget(frame);

    output->setParent(frame);
    input->setParent(frame);
    //p->move(100,100);
}

VDSL::~VDSL()
{
    delete ui;
}
