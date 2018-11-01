#ifndef INPUT_H
#define INPUT_H

#include "port.h"

class Input : public Port
{
    Q_OBJECT
public:
    explicit Input(QWidget *parent = nullptr, QString name = "Input");

    Type type() const;
    bool isConnected(Port *); //NOTE: inputs should only have one connection at a time.

protected:

    void onConnect(Port *);
    void onDisconnect(Port *);
};

#endif // INPUT_H
