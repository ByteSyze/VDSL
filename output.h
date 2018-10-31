#ifndef OUTPUT_H
#define OUTPUT_H

#include "port.h"
#include <QVector>

class Output : public Port
{
    Q_OBJECT
public:
    explicit Output(QWidget *parent = nullptr);

    virtual const char* getOutputSignal() = 0;

private:

    QVector<Port*> *connectedPorts;

};

#endif // OUTPUT_H
