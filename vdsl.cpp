#include "vdsl.h"
#include "ui_vdsl.h"

#include "vdslframe.h"

#include "Modules/module.h"
#include "Ports/stringinput.h"
#include "Ports/stringoutput.h"

#include <QPainter>

#include <Modules/stringinputfield.h>
#include <Modules/concatenate.h>
#include <Modules/stringprinter.h>

Port* VDSL::selectedPort = nullptr;

VDSL::VDSL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VDSL)
{
    ui->setupUi(this);

    frame = new VDSLFrame;
    ui->scrollArea->setWidget(frame);

    StringInputField *field1 = new StringInputField;
    StringInputField *field2 = new StringInputField;

    connect(frame, SIGNAL(tick()), field1, SLOT(onDataReady()));
    connect(frame, SIGNAL(tick()), field2, SLOT(onDataReady()));

    Concatenate *concat      = new Concatenate;

    StringPrinter *printer   = new StringPrinter;

    field1->setParent(frame);
    field2->setParent(frame);

    concat->setParent(frame);

    printer->setParent(frame);
}

VDSL::~VDSL()
{
    delete ui;
}

void VDSL::on_pushButtonStart_clicked()
{
    frame->run();
}
