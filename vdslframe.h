#ifndef VDSLFRAME_H
#define VDSLFRAME_H

#include <QFrame>

class VDSLFrame : public QFrame
{
    Q_OBJECT
public:
    explicit VDSLFrame(QWidget *parent = nullptr);

    void run();

private:

    void paintEvent(QPaintEvent *event) override;

    void mouseMoveEvent(QMouseEvent *) override;
    void mousePressEvent(QMouseEvent *) override;

signals:

    void tick(void);

};

#endif // VDSLFRAME_H
