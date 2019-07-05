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

#include "stringtofloat.h"

StringToFloat::StringToFloat(QWidget *parent) : Module("String To Float", parent)
{
    in = new StringInput;
    in->setName("String");

    out = new FloatOutput;
    out->setName("Float");

    registerInput(in);

    registerOutput(out);
}

void StringToFloat::run()
{
    out->send(in->data().toFloat());
}

Module *StringToFloat::clone()
{
    return new StringToFloat;
}
