#ifndef STRINGPRINTER_H
#define STRINGPRINTER_H

#include <module.h>
#include <stringinput.h>

class StringPrinter : public Module
{
    Q_OBJECT
public:
    explicit StringPrinter(QWidget *parent = nullptr);

    void run();

private:

    StringInput *in;

    QLabel *display;

signals:

public slots:


};

#endif // STRINGPRINTER_H
