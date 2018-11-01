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

    void mousePressEvent(QMouseEvent *event) override;

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

    QRectF m_Border;
    QRectF m_Center;

signals:

    void clicked(void);

};

#endif // CONNECTOR_H
