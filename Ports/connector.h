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

#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QWidget>

class Connector : public QWidget
{
    Q_OBJECT
public:
    explicit Connector(QWidget *parent = nullptr);

private:

    void paintEvent(QPaintEvent *) override;

    void mousePressEvent(QMouseEvent *) override;

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

    QRectF m_Border;
    QRectF m_Center;

signals:

    void clicked(void);

};

#endif // CONNECTOR_H
