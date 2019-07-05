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

#ifndef WAVEGENERATOR_H
#define WAVEGENERATOR_H

#include <QTime>
#include <Modules/module.h>
#include <Ports/floatinput.h>
#include <Ports/floatoutput.h>

class WaveGenerator : public Module
{
    Q_OBJECT
public:
    explicit WaveGenerator(QWidget *parent = nullptr);
    ~WaveGenerator();

    void run();

    Module *clone();

private:

    FloatOutput *out;

    float angle           = 0.00;
    float angularVelocity = 0.25;

    static QTime generatorTime;

};

#endif // WAVEGENERATOR_H
