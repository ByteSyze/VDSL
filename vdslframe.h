#ifndef VDSLFRAME_H
#define VDSLFRAME_H

#include <QFrame>

class VDSLFrame : public QFrame
{
    Q_OBJECT
public:
    explicit VDSLFrame(QWidget *parent = nullptr);

private:

    void paintEvent(QPaintEvent *event) override;

    void mouseMoveEvent(QMouseEvent *) override;
    void mousePressEvent(QMouseEvent *) override;

    void keyPressEvent(QKeyEvent *) override;

signals:

    void run(void);

};

#endif // VDSLFRAME_H
