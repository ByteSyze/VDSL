#ifndef LINEGRAPH_H
#define LINEGRAPH_H

#include "linegraphdisplay.h"
#include "Modules/module.h"
#include "Ports/floatinput.h"

class LineGraph : public Module
{
    Q_OBJECT

public:
    explicit LineGraph(QWidget *parent = nullptr);
    ~LineGraph();

    void run();

private:

    FloatInput *in;

    LineGraphDisplay *display;

};


#endif // LINEGRAPH_H
