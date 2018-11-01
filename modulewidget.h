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
    virtual ~ModuleWidget() override;

protected:

    void registerInput(Input *);
    void unregisterInput(Input *);

    void registerOutput(Output *);
    void unregisterOutput(Output *);

    void performAction(void);

private:

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    QList<Input *>  *inputs;
    QList<Output *> *outputs;

    QHBoxLayout *mainLayout;
    QLayout     *contentLayout;

    QVBoxLayout *inputLayout;
    QVBoxLayout *outputLayout;

    bool isBeingDragged = false;

signals:

public slots:

    void onDataReady();

};

#endif // MODULEWIDGET_H
