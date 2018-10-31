#ifndef TRANSCEIVER_H
#define TRANSCEIVER_H

#include <QColor>
#include <QLayout>
#include <QWidget>
#include "input.h"
#include "output.h"

class Transceiver : public QWidget
{
    Q_OBJECT
public:
    explicit Transceiver(QWidget *parent = nullptr);
    virtual ~Transceiver() = 0;

    void highlight(QColor);

protected:

    Input*  inputs;
    Output* outputs;

private:

    QHBoxLayout *mainLayout;
    QVBoxLayout *inputLayout;
    QVBoxLayout *outputLayout;

signals:

public slots:
};

#endif // TRANSCEIVER_H
