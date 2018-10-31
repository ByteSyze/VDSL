#ifndef STRINGOUTPUT_H
#define STRINGOUTPUT_H

#include "port.h"

class StringOutput : public Port
{
    Q_OBJECT

public:
    explicit StringOutput(QWidget *parent = nullptr);

protected:

    const char* interface();
    Type type() const;

    void onConnect();

public slots:

    void onConnect(Port*);

signals:

    void send(QString);

};

#endif // STRINGOUTPUT_H
