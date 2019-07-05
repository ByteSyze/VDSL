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

#include "wavegenerator.h"

WaveGenerator::WaveGenerator(QWidget *parent) : Module("Wave Generator", parent, ModuleType::emitter)
{
    out = new FloatOutput;
    out->setName("Output");

    registerOutput(out);
}

WaveGenerator::~WaveGenerator()
{

}

void WaveGenerator::run()
{
    angle += angularVelocity;
    out->send(sin(angle));
}

Module *WaveGenerator::clone()
{
    return new WaveGenerator;
}
