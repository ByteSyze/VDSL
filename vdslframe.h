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

#ifndef VDSLFRAME_H
#define VDSLFRAME_H

#include <QStackedWidget>
#include <Modules/module.h>

class VDSLFrame : public QFrame
{
    Q_OBJECT
public:
    explicit VDSLFrame(QWidget *parent = nullptr);

    void run();

    QPoint userSelectionP1();
    QPoint userSelectionP2();

    bool   isUserSelecting();
    bool   isUserDragging();

private:

    bool m_IsUserSelecting = false;
    QPoint selectionP1, selectionP2;

    QList<Module *> *selectedModules;

    bool m_IsUserDragging = false;
    QPoint dragAnchor;

    void selectModules(QRect);
    void deselectModules();

    void invalidateModules();

    void mouseMoveEvent(QMouseEvent *)     override;
    void mousePressEvent(QMouseEvent *)    override;
    void mouseReleaseEvent(QMouseEvent *)  override;

    void dragEnterEvent(QDragEnterEvent *) override;
    void dropEvent(QDropEvent *)           override;

signals:

    void tick(void);

};

#endif // VDSLFRAME_H
