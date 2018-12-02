#include "linegraph.h"

LineGraph::LineGraph(QWidget *parent) : Module("Line Graph", parent)
{
    display = new LineGraphDisplay(32, this);
    display->setMinimumSize(380,240);

    contentLayout->addWidget(display);

    in = new FloatInput(this);
    in->setName("Data");

    registerInput(in);
}

LineGraph::~LineGraph()
{
    display->deleteLater();
}

void LineGraph::run()
{
    display->addData(in->data());
}

Module *LineGraph::clone()
{
    return new LineGraph;
}
