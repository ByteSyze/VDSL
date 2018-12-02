#include "linegraphdisplay.h"
#include <QPainter>

LineGraphDisplay::LineGraphDisplay(uint32_t maxBufferSize, QWidget *parent) : QWidget(parent)
{
    this->maxBufferSize = maxBufferSize;
    graphData = new QList<float>;
}

LineGraphDisplay::~LineGraphDisplay()
{
    delete graphData;
}

void LineGraphDisplay::addData(float data)
{
    *(graphData) << data;

    if(graphData->size() > maxBufferSize)
        graphData->removeFirst();

    update();
}

void LineGraphDisplay::paintEvent(QPaintEvent* e)
{
    if(graphData->size() > 1)
    {
        QPainter *painter = new QPainter(this);
        painter->setPen(Qt::black);

        /*Graph maximum and minimum values for scaling purposes.*/
        float maxData = *std::max_element(graphData->begin(), graphData->end());
        float minData = *std::min_element(graphData->begin(), graphData->end());

        float graphHeight = height();

        float xScale = (width()-60)/graphData->size();
        float yScale = graphHeight/(maxData-minData)-1;

        for(int i = 1; i < 5; i++)
        {
            QLine valueMarker(width()-60, graphHeight/5 * i, width()-30, graphHeight/5 * i);
            painter->drawLine(valueMarker);

            painter->drawText(width()-50, graphHeight/5 * i - 1, QString::number(minData + ((maxData-minData)/5 * (5-i))));
        }

        int index = 0;

        QList<float>::iterator p1 = graphData->begin();
        QList<float>::iterator p2 = (p1+1);

        do
        {
            QLine line = QLine(index*xScale, graphHeight - (*(p1) - minData)*yScale, (index+1)*xScale, graphHeight - (*(p2) - minData)*yScale);
            painter->drawLine(line);

            p1 = p2;
            p2++;

            index++;

        } while(p2 != graphData->end());
    }
}
