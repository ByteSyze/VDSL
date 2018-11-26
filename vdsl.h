#ifndef VDSL_H
#define VDSL_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QTimer>
#include "vdslframe.h"

class Port;
class Module;

namespace Ui {
class VDSL;
}

class VDSL : public QMainWindow
{
    Q_OBJECT

public:
    explicit VDSL(QWidget *parent = nullptr);
    ~VDSL();

    static Port*   selectedPort;
    static Module* selectedModule;

private:

    VDSLFrame *frame;

    bool isRunning = false;

    QTimer *mainTimer;

private slots:
    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

    void tick();

    void on_moduleTree_itemPressed(QTreeWidgetItem *item, int column);

    void on_moduleTree_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::VDSL *ui;
};

#endif // VDSL_H
