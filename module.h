#ifndef MODULE_H
#define MODULE_H

#include <QColor>
#include <QLayout>
#include <QList>
#include <QFrame>
#include "input.h"
#include "output.h"

class Module : public QFrame
{
    Q_OBJECT
public:
    explicit Module(QString name = "", QWidget *parent = nullptr);
    virtual ~Module() override;

    QString name();

protected:

    void registerInput(Input *);
    void unregisterInput(Input *);

    void registerOutput(Output *);
    void unregisterOutput(Output *);

    virtual void run() = 0;

private:

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    QList<Input *>  *inputs;
    QList<Output *> *outputs;

    QLabel      *moduleLabel;

    QHBoxLayout *mainLayout;
    QLayout     *contentLayout;

    QVBoxLayout *inputLayout;
    QVBoxLayout *outputLayout;

    QString m_Name;

    bool isBeingDragged = false;

signals:

public slots:

    void onDataReady();
    void onInit();

};

#endif // MODULE_H