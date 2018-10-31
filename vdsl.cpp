#include "vdsl.h"
#include "ui_vdsl.h"
#include "vdslframe.h"
#include "port.h"
#include <QPainter>

Port* VDSL::selectedPort = nullptr;

VDSL::VDSL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VDSL)
{
    ui->setupUi(this);

    Port *p = new Port(nullptr, "output");

    //ui->verticalLayout->addWidget(p);
    VDSLFrame *frame = new VDSLFrame;
    ui->scrollArea->setWidget(frame);

    p->setParent(frame);
    //p->move(100,100);
}

VDSL::~VDSL()
{
    delete ui;
}
