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

#ifndef VDSL_H
#define VDSL_H

#include <QMainWindow>
#include <QStackedLayout>
#include <QTreeWidgetItem>
#include <QTimer>

#include "vdslframe.h"
#include "vdslframeoverlay.h"

class Port;
class Module;

namespace Ui {
class VDSL;
}

class VDSL : public QMainWindow
{
    Q_OBJECT

public:
    explicit VDSL(QWidget *parent = nullptr);
    ~VDSL();

    static Port*   selectedPort;

    static QList<Module *>* selectedModules;

    void initializeModuleTree();
    void addToModuleTree(QTreeWidgetItem *);

private:

    VDSLFrame        *frame;
    VDSLFrameOverlay *overlay;

    QStackedLayout   *frameLayout;

    bool isRunning = false;

    QTimer *mainTimer;

private slots:
    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

    void tick();

    void keyPressEvent(QKeyEvent *) override;

    void on_moduleTree_itemPressed(QTreeWidgetItem *item, int column);

    void on_moduleTree_itemClicked(QTreeWidgetItem *item, int column);

    void on_sliderSpeedControl_sliderMoved(int position);

private:
    Ui::VDSL *ui;
};

#endif // VDSL_H
