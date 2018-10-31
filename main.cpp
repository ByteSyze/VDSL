#include "vdsl.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VDSL w;
    w.show();

    return a.exec();
}
