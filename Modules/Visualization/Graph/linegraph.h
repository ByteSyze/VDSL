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

    Module *clone();

private:

    FloatInput *in;

    LineGraphDisplay *display;

};


#endif // LINEGRAPH_H
