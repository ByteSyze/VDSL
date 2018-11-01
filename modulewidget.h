#ifndef MODULEWIDGET_H
#define MODULEWIDGET_H

#include <QColor>
#include <QLayout>
#include <QList>
#include <QFrame>
#include "input.h"
#include "output.h"

class ModuleWidget : public QFrame
{
    Q_OBJECT
public:
    explicit ModuleWidget(QWidget *parent = nullptr);
    virtual ~ModuleWidget();

protected:

    QList<Input *>  *inputs;
    QList<Output *> *outputs;

private:

    bool isBeingDragged = false;

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    QHBoxLayout *mainLayout;
    QLayout     *contentLayout;

    QVBoxLayout *inputLayout;
    QVBoxLayout *outputLayout;

signals:

public slots:
};

#endif // MODULEWIDGET_H
