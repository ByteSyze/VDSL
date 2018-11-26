#include "linegraphdisplay.h"
#include <QPainter>

LineGraphDisplay::LineGraphDisplay(uint32_t maxDataSize, QWidget *parent) : QWidget(parent)
{
    this->maxDataSize = maxDataSize;
    graphData = new QList<float>;
}

LineGraphDisplay::~LineGraphDisplay()
{
    delete graphData;
}

void LineGraphDisplay::addData(float data)
{
    *(graphData) << data;

    if(graphData->size() > maxDataSize)
        graphData->removeFirst();

    update();
}

void LineGraphDisplay::paintEvent(QPaintEvent* e)
{

    if(graphData->size() > 1)
    {
        QPainter *painter = new QPainter(this);
        painter->setPen(Qt::black);

        QList<float>::iterator p1 = graphData->begin();
        QList<float>::iterator p2 = (p1+1);

        /*Graph maximum and minimum values for scaling purposes.*/
        float maxData = *std::max_element(graphData->begin(), graphData->end());
        float minData = *std::min_element(graphData->begin(), graphData->end());

        float xScale = width()/graphData->size();
        float yScale = height()/(maxData-minData);

        int index = 0;

        do
        {
            //TODO  graph data
            QLineF line = QLineF(index*xScale, (*(p1) - minData)*yScale, (index+1)*xScale, (*(p2) - minData)*yScale);
            painter->drawLine(line);

            p1 = p2;
            p2++;

            index++;

        } while(p2 != graphData->end());
    }
}
