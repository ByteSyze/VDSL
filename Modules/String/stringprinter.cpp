#include "stringprinter.h"

StringPrinter::StringPrinter(QWidget *parent) : Module("String Printer", parent)
{
    in = new StringInput;
    in->setName("Input");

    display = new QLabel;

    contentLayout->addWidget(display);

    registerInput(in);
}

void StringPrinter::run()
{
    display->setText("\"" + in->data() + "\"");
}

Module *StringPrinter::clone()
{
    return new StringPrinter;
}
