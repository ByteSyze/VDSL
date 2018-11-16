#ifndef OUTPUT_H
#define OUTPUT_H

#include "port.h"
#include <QList>

class Output : public Port
{
    Q_OBJECT
public:
    explicit Output(QWidget *parent = nullptr, QString name = "Output");
    ~Output();

    Type type() const;
    bool isConnected(Port *);

    QList<Port *> *getConnected();

private:

    QList<Port*> *connectedPorts;

protected:

    void onConnect(Port *);
    void onDisconnect(Port *);

};

#endif // OUTPUT_H
