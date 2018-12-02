#ifndef VDSLFRAME_H
#define VDSLFRAME_H

#include <QStackedWidget>
#include <Modules/module.h>

class VDSLFrame : public QFrame
{
    Q_OBJECT
public:
    explicit VDSLFrame(QWidget *parent = nullptr);

    void run();

    QPoint userSelectionP1();
    QPoint userSelectionP2();

    bool   isUserSelecting();

private:

    bool m_isUserSelecting = false;
    QPoint selectionP1, selectionP2;

    QList<Module *> *selectedModules;

    void invalidateModules();

    void mouseMoveEvent(QMouseEvent *)     override;
    void mousePressEvent(QMouseEvent *)    override;
    void mouseReleaseEvent(QMouseEvent *)  override;

    void dragEnterEvent(QDragEnterEvent *) override;
    void dropEvent(QDropEvent *)           override;

signals:

    void tick(void);

};

#endif // VDSLFRAME_H
