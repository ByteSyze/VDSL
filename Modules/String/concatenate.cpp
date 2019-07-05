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

#include "concatenate.h"

Concatenate::Concatenate(QWidget *parent) : Module("Concatenate", parent)
{
    in1 = new StringInput;
    in1->setName("Input 1");

    in2 = new StringInput;
    in2->setName("Input 2");

    out = new StringOutput;
    out->setName("Output");

    registerInput(in1);
    registerInput(in2);

    registerOutput(out);
}

void Concatenate::run()
{
    out->send(in1->data() + " " + in2->data());
}

Module *Concatenate::clone()
{
    return new Concatenate;
}
