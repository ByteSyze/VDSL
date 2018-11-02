#include "stringinputfield.h"

StringInputField::StringInputField(QWidget *parent) : Module("String Input", parent)
{
    out = new StringOutput;
    out->setName("Output");

    inputField = new QLineEdit;

    contentLayout->addWidget(inputField);

    registerOutput(out);
}

void StringInputField::run()
{
    out->send(inputField->text());
}
