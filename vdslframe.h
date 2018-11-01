#ifndef VDSLFRAME_H
#define VDSLFRAME_H

#include <QFrame>

class VDSLFrame : public QFrame
{
public:
    explicit VDSLFrame(QWidget *parent = nullptr);

private:

    void paintEvent(QPaintEvent *event) override;

    void mouseMoveEvent(QMouseEvent *) override;
    void mousePressEvent(QMouseEvent *) override;
};

#endif // VDSLFRAME_H
