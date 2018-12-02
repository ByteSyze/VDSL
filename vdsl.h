#ifndef VDSL_H
#define VDSL_H

#include <QMainWindow>
#include <QStackedLayout>
#include <QTreeWidgetItem>
#include <QTimer>

#include "vdslframe.h"
#include "vdslframeoverlay.h"

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

    void initializeModuleTree();
    void addToModuleTree(QTreeWidgetItem *);

private:

    VDSLFrame        *frame;
    VDSLFrameOverlay *overlay;

    QStackedLayout   *frameLayout;

    bool isRunning = false;

    QTimer *mainTimer;

private slots:
    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

    void tick();

    void on_moduleTree_itemPressed(QTreeWidgetItem *item, int column);

    void on_moduleTree_itemClicked(QTreeWidgetItem *item, int column);

    void on_sliderSpeedControl_sliderMoved(int position);

private:
    Ui::VDSL *ui;
};

#endif // VDSL_H
