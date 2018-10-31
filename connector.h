#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QWidget>

class Connector : public QWidget
{
    Q_OBJECT
public:
    explicit Connector(QWidget *parent = nullptr);

private:

    void paintEvent(QPaintEvent *event) override;

    QRectF m_Border;
    QRectF m_Center;

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

};

#endif // CONNECTOR_H
