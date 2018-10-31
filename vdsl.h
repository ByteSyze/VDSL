#ifndef VDSL_H
#define VDSL_H

#include <QMainWindow>

class Port;

namespace Ui {
class VDSL;
}

class VDSL : public QMainWindow
{
    Q_OBJECT

public:
    explicit VDSL(QWidget *parent = nullptr);
    ~VDSL();

    static Port* selectedPort;

private:
    Ui::VDSL *ui;
};

#endif // VDSL_H
