#ifndef VDSLSCROLLAREA_H
#define VDSLSCROLLAREA_H

#include <QFrame>

class VDSLFrame : public QFrame
{
public:
    explicit VDSLFrame(QWidget *parent = nullptr);

private:

    void paintEvent(QPaintEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // VDSLSCROLLAREA_H
