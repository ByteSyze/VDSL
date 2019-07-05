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

#include "addfloat.h"

AddFloat::AddFloat(QWidget *parent) : Module("Add Floats", parent)
{
    in1 = new FloatInput;
    in1->setName("Float 1");

    in2 = new FloatInput;
    in2->setName("Float 2");

    out = new FloatOutput;
    out->setName("Sum");

    registerInput(in1);
    registerInput(in2);

    registerOutput(out);
}

void AddFloat::run()
{
    out->send(in1->data() + in2->data());
}

Module *AddFloat::clone()
{
    return new AddFloat;
}
