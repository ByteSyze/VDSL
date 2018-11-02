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

    bool isDataReady();
    void invalidateData();

protected:

    void setDataReady(bool);

    void onConnect(Port *);
    void onDisconnect(Port *);

    bool allowConnection(Port *);

private:

    Port *connectedPort = nullptr;

    bool m_DataReady = false;

signals:

    void dataReady(void);

};

#endif // INPUT_H
