#ifndef VDSLFRAMEOVERLAY_H
#define VDSLFRAMEOVERLAY_H

#include "vdslframe.h"

#include <QColor>
#include <QWidget>

class VDSLFrameOverlay : public QWidget
{
    Q_OBJECT
public:
    explicit VDSLFrameOverlay(QWidget *parent = nullptr);

    void setFrame(VDSLFrame *);

private:

    VDSLFrame *frame;

    QColor selectionColor;
    QColor selectionBorderColor;

    void paintEvent(QPaintEvent *) override;

signals:

public slots:
};

#endif // VDSLFRAMEOVERLAY_H
