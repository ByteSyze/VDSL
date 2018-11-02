#include "vdsl.h"
#include "ui_vdsl.h"

#include "vdslframe.h"

#include "module.h"
#include "stringoutput.h"
#include "stringinput.h"
#include <QPainter>

Port* VDSL::selectedPort = nullptr;

VDSL::VDSL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VDSL)
{
    ui->setupUi(this);

    VDSLFrame *frame = new VDSLFrame;
    ui->scrollArea->setWidget(frame);
}

VDSL::~VDSL()
{
    delete ui;
}
