#include "vdsl.h"
#include "ui_vdsl.h"

#include "vdslframe.h"
#include "vdslframeoverlay.h"

#include "Modules/module.h"
#include "Ports/stringinput.h"
#include "Ports/stringoutput.h"

#include "Modules/moduletreewidgetitem.h"

#include <QPainter>
#include <QDebug>
#include <QDrag>
#include <QMimeData>

#include <QStackedLayout>

#include <Modules/String/stringinputfield.h>
#include <Modules/String/concatenate.h>
#include <Modules/String/stringprinter.h>

#include <Modules/Math/Float/addfloat.h>
#include <Modules/Math/Float/wavegenerator.h>
#include <Modules/Convert/stringtofloat.h>
#include <Modules/Convert/floattostring.h>

#include <Modules/Visualization/Graph/linegraph.h>

Port* VDSL::selectedPort = nullptr;

VDSL::VDSL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VDSL)
{
    ui->setupUi(this);

    QTime::currentTime().start();

    frameLayout = new QStackedLayout;
    frameLayout->setStackingMode(QStackedLayout::StackAll);

    frame = new VDSLFrame;
    overlay = new VDSLFrameOverlay;

    overlay->setFrame(frame);

    frameLayout->addWidget(frame);
    frameLayout->addWidget(overlay);

    ui->scrollArea->setLayout(frameLayout);

    StringInputField *field1 = new StringInputField;
    StringInputField *field2 = new StringInputField;

    WaveGenerator *wavgen    = new WaveGenerator;

    connect(frame, SIGNAL(tick()), field1, SLOT(onDataReady()));
    connect(frame, SIGNAL(tick()), field2, SLOT(onDataReady()));
    connect(frame, SIGNAL(tick()), wavgen, SLOT(onDataReady()));

    Concatenate   *concat    = new Concatenate;

    AddFloat      *addfl     = new AddFloat;

    StringToFloat *stof1     = new StringToFloat;
    StringToFloat *stof2     = new StringToFloat;

    FloatToString *ftos      = new FloatToString;

    LineGraph     *graph     = new LineGraph;

    QTreeWidgetItem *convertCat = new QTreeWidgetItem;
    convertCat->setText(0,"Convert");

    ModuleTreeWidgetItem *ftosItem = new ModuleTreeWidgetItem;
    ftosItem->setText(0,"Float to String");
    ftosItem->setModulePrototype(new FloatToString);

    ModuleTreeWidgetItem *stofItem = new ModuleTreeWidgetItem;
    stofItem->setText(0,"String to Float");
    stofItem->setModulePrototype(new StringToFloat);

    QTreeWidgetItem *mathCat = new QTreeWidgetItem;
    mathCat->setText(0, "Math");

    ModuleTreeWidgetItem *mathFloatCat = new ModuleTreeWidgetItem;
    mathFloatCat->setText(0, "Float");

    ModuleTreeWidgetItem *addFloatItem = new ModuleTreeWidgetItem;
    addFloatItem->setText(0, "Add Float");
    addFloatItem->setModulePrototype(new AddFloat);

    convertCat->addChild(ftosItem);
    convertCat->addChild(stofItem);

    mathCat->addChild(mathFloatCat);
    mathFloatCat->addChild(addFloatItem);

    ui->moduleTree->headerItem()->setText(0,"Modules");
    ui->moduleTree->setColumnCount(1);
    ui->moduleTree->addTopLevelItem(convertCat);
    ui->moduleTree->addTopLevelItem(mathCat);

    StringPrinter *printer   = new StringPrinter;

    field1->setParent(frame);
    field2->setParent(frame);

    concat->setParent(frame);

    addfl->setParent(frame);

    wavgen->setParent(frame);

    stof1->setParent(frame);
    stof2->setParent(frame);

    ftos->setParent(frame);

    printer->setParent(frame);

    graph->setParent(frame);

    mainTimer = new QTimer(this);

    connect(mainTimer, SIGNAL(timeout()), this, SLOT(tick()));

    mainTimer->start(16); //Roughly 63 ticks per second
}

VDSL::~VDSL()
{
    mainTimer->deleteLater();
    delete ui;
}

void VDSL::tick()
{
    if(isRunning)
    {
        frame->run();
    }
}

void VDSL::on_pushButtonStart_clicked()
{
    isRunning = true;
}

void VDSL::on_pushButtonStop_clicked()
{
    isRunning = false;
}

void VDSL::on_moduleTree_itemPressed(QTreeWidgetItem *item, int column)
{
    ModuleTreeWidgetItem *modItem = dynamic_cast<ModuleTreeWidgetItem*>(item);

    if(modItem != nullptr)
    {

        qDebug() << "item pressed";

        QDrag drag(modItem->cloneModulePrototype());

        QMimeData *data = new QMimeData;
        data->setData("vdsl::createitem", item->text(0).toLocal8Bit());

        drag.setMimeData(data);

        Qt::DropAction action = drag.exec();
    }
}

void VDSL::on_moduleTree_itemClicked(QTreeWidgetItem *item, int column)
{

}

void VDSL::on_sliderSpeedControl_sliderMoved(int position)
{
    mainTimer->setInterval(ui->sliderSpeedControl->maximum() - position);
}
