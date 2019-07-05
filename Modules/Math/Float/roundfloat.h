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

#ifndef ROUNDFLOAT_H
#define ROUNDFLOAT_H

#include <Modules/module.h>
#include <Ports/floatinput.h>
#include <Ports/floatoutput.h>

class RoundFloat : public Module
{
    Q_OBJECT
public:
    explicit RoundFloat(QWidget *parent = nullptr);

    void run();

    Module *clone();

private:

    FloatInput *in;

    FloatOutput *out;
};


#endif // ROUNDFLOAT_H
