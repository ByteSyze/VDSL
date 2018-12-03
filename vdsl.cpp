#include "vdsl.h"
#include "ui_vdsl.h"

#include "vdslframe.h"
#include "vdslframeoverlay.h"

#include "Modules/module.h"
#include "Ports/stringinput.h"
#include "Ports/stringoutput.h"

#include "Modules/moduletreewidgetitem.h"

#include <Modules/String/stringinputfield.h>
#include <Modules/String/concatenate.h>
#include <Modules/String/stringprinter.h>

#include <Modules/Math/Float/addfloat.h>
#include <Modules/Math/Float/multiplyfloat.h>
#include <Modules/Math/Float/roundfloat.h>
#include <Modules/Math/Float/wavegenerator.h>
#include <Modules/Convert/stringtofloat.h>
#include <Modules/Convert/floattostring.h>

#include <Modules/Visualization/Graph/linegraph.h>

#include <QPainter>
#include <QDebug>

#include <QDrag>
#include <QMimeData>

#include <QStackedLayout>

Port* VDSL::selectedPort                = nullptr;

QList<Module *>* VDSL::selectedModules  = new QList<Module *>;

VDSL::VDSL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VDSL)
{
    ui->setupUi(this);

    initializeModuleTree();

    frameLayout = new QStackedLayout;
    frameLayout->setStackingMode(QStackedLayout::StackAll);

    frame = new VDSLFrame;
    overlay = new VDSLFrameOverlay;

    overlay->setFrame(frame);

    overlay->setMinimumSize(QSize(10000,10000));
    frame->setMinimumSize(QSize(10000,10000));

    frameLayout->addWidget(frame);
    frameLayout->addWidget(overlay);

    ui->scrollArea->setLayout(frameLayout);

    mainTimer = new QTimer(this);

    connect(mainTimer, SIGNAL(timeout()), this, SLOT(tick()));

    mainTimer->start(16); //Roughly 63 ticks per second
}

VDSL::~VDSL()
{
    mainTimer->deleteLater();
    delete ui;
}

void VDSL::initializeModuleTree()
{
    ui->moduleTree->headerItem()->setText(0,"Modules");
    ui->moduleTree->setColumnCount(1);

    //// Data Conversion category ////

    QTreeWidgetItem *convertCat = new QTreeWidgetItem;
    convertCat->setText(0,"Convert");

    ModuleTreeWidgetItem *ftosItem = new ModuleTreeWidgetItem;
    ftosItem->setText(0,"Float to String");
    ftosItem->setModulePrototype(new FloatToString);

    ModuleTreeWidgetItem *stofItem = new ModuleTreeWidgetItem;
    stofItem->setText(0,"String to Float");
    stofItem->setModulePrototype(new StringToFloat);

    convertCat->addChild(ftosItem);
    convertCat->addChild(stofItem);

    //// Math category ////

    QTreeWidgetItem *mathCat = new QTreeWidgetItem;
    mathCat->setText(0, "Math");

    /// Float sub-category ///

    QTreeWidgetItem *mathFloatCat = new QTreeWidgetItem;
    mathFloatCat->setText(0, "Float");

    ModuleTreeWidgetItem *addFloatItem = new ModuleTreeWidgetItem;
    addFloatItem->setText(0, "Add");
    addFloatItem->setModulePrototype(new AddFloat);

    ModuleTreeWidgetItem *roundFloatItem = new ModuleTreeWidgetItem;
    roundFloatItem->setText(0, "Round");
    roundFloatItem->setModulePrototype(new RoundFloat);

    ModuleTreeWidgetItem *multiplyFloatItem = new ModuleTreeWidgetItem;
    multiplyFloatItem->setText(0, "Multiply");
    multiplyFloatItem->setModulePrototype(new MultiplyFloat);

    ModuleTreeWidgetItem *waveGenItem = new ModuleTreeWidgetItem;
    waveGenItem->setText(0, "Wave Generator");
    waveGenItem->setModulePrototype(new WaveGenerator);

    mathCat->addChild(mathFloatCat);
    mathFloatCat->addChild(addFloatItem);
    mathFloatCat->addChild(multiplyFloatItem);
    mathFloatCat->addChild(roundFloatItem);
    mathFloatCat->addChild(waveGenItem);

    //// String category ////

    QTreeWidgetItem *stringCat = new QTreeWidgetItem;
    stringCat->setText(0, "String");

    ModuleTreeWidgetItem *concatItem = new ModuleTreeWidgetItem;
    concatItem->setText(0, "Concatenate");
    concatItem->setModulePrototype(new Concatenate);

    ModuleTreeWidgetItem *sifItem = new ModuleTreeWidgetItem;
    sifItem->setText(0, "Input Field");
    sifItem->setModulePrototype(new StringInputField);

    ModuleTreeWidgetItem *sprinterItem = new ModuleTreeWidgetItem;
    sprinterItem->setText(0, "Printer");
    sprinterItem->setModulePrototype(new StringPrinter);

    stringCat->addChild(concatItem);
    stringCat->addChild(sifItem);
    stringCat->addChild(sprinterItem);

    //// Data visualization /////

    /// Graphs ///

    QTreeWidgetItem *graphCat = new QTreeWidgetItem;
    graphCat->setText(0, "Graph");

    ModuleTreeWidgetItem *lineGraphItem = new ModuleTreeWidgetItem;
    lineGraphItem->setText(0, "Line Graph");
    lineGraphItem->setModulePrototype(new LineGraph);

    graphCat->addChild(lineGraphItem);

    //// Add top-level items to module tree ////

    addToModuleTree(convertCat);
    addToModuleTree(mathCat);
    addToModuleTree(stringCat);
    addToModuleTree(graphCat);
}

void VDSL::addToModuleTree(QTreeWidgetItem *treeItem)
{
    ui->moduleTree->addTopLevelItem(treeItem);
}

void VDSL::tick()
{
    if(isRunning)
    {
        frame->run();
    }
}

void VDSL::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Delete && !VDSL::selectedModules->isEmpty())
    {
        // Delete selected modules.
        QList<Module *>::iterator it;

        for(it = VDSL::selectedModules->begin(); it != VDSL::selectedModules->end(); it++)
        {
            (*it)->deleteLater();
        }

        VDSL::selectedModules->clear();

        frame->update();
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
