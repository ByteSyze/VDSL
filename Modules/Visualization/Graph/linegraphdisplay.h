#ifndef LINEGRAPHDISPLAY_H
#define LINEGRAPHDISPLAY_H

#include <QWidget>

class LineGraphDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit LineGraphDisplay(uint32_t maxBufferSize=256, QWidget *parent = nullptr);
    ~LineGraphDisplay();

    void addData(float data);

protected:

    void paintEvent(QPaintEvent  *e);

private:

    uint32_t maxBufferSize;

    QList<float> *graphData;

};
#endif // LINEGRAPHDISPLAY_H
