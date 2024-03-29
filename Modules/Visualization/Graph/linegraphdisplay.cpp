/*
    Copyright (C) 2018-2019 Tyler Hackett

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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
    QPainter *painter = new QPainter(this);
    painter->setPen(Qt::black);

    painter->drawRect(60, 0, width()-61, height()-1);

    if(graphData->size() > 1)
    {
        /*Grab maximum and minimum values for scaling purposes.*/
        float maxData = *std::max_element(graphData->begin(), graphData->end());
        float minData = *std::min_element(graphData->begin(), graphData->end());

        float graphHeight = height();

        float xScale = (width()-60)/graphData->size();
        float yScale = graphHeight/(maxData-minData);

        for(int i = 1; i < 5; i++)
        {
            QLine valueMarker(60, graphHeight/5 * i, 75, graphHeight/5 * i);
            painter->drawLine(valueMarker);

            painter->drawText(QRect(0, graphHeight/5 * i - 6,60,15), Qt::AlignRight, QString::asprintf("%.3f", minData + ((maxData-minData)/5 * (5-i))));
        }

        int index = 0;

        QList<float>::iterator p1 = graphData->begin();
        QList<float>::iterator p2 = (p1+1);

        do
        {
            QLine line = QLine(60 + index*xScale, graphHeight - (*(p1) - minData)*yScale, 60 + (index+1)*xScale, graphHeight - (*(p2) - minData)*yScale);
            painter->drawLine(line);

            p1 = p2;
            p2++;

            index++;

        } while(p2 != graphData->end());
    }
}
