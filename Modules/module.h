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

#ifndef MODULE_H
#define MODULE_H

#include <QColor>
#include <QLayout>
#include <QList>
#include <QFrame>
#include "Ports/input.h"
#include "Ports/output.h"

class Module : public QFrame
{
    Q_OBJECT
public:

    enum class ModuleType
    {
        emitter, //Emitter modules are the starting points in the program.
        dataDependent //Data dependent modules need data before they can emit.
    };

    explicit Module(QString name = "", QWidget *parent = nullptr, ModuleType type = ModuleType::dataDependent);
    virtual ~Module() override;

    void invalidate();

    QString name();

    ModuleType type();

    virtual Module *clone() = 0;

protected:

    void registerInput(Input *);
    void unregisterInput(Input *);

    void registerOutput(Output *);
    void unregisterOutput(Output *);

    virtual void run() = 0;

    QVBoxLayout *contentLayout;

private:

    void disconnectInputs();
    void disconnectOutputs();

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    QList<Input *>  *inputs;
    QList<Output *> *outputs;

    QLabel      *moduleLabel;

    QHBoxLayout *mainLayout;

    QVBoxLayout *inputLayout;
    QVBoxLayout *outputLayout;

    QString m_Name;

    ModuleType m_Type;

    bool isBeingDragged = false;

signals:

public slots:

    void onDataReady();

};

#endif // MODULE_H
