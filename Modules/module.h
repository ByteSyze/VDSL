#ifndef MODULE_H
#define MODULE_H

#include <QColor>
#include <QLayout>
#include <QList>
#include <QFrame>
#include "Ports/input.h"
#include "Ports/output.h"

class Module : public QFrame
{
    Q_OBJECT
public:

    enum class ModuleType
    {
        emitter, //Emitter modules are the starting points in the program.
        dataDependent //Data dependent modules need data before they can emit.
    };

    explicit Module(QString name = "", QWidget *parent = nullptr, ModuleType type = ModuleType::dataDependent);
    virtual ~Module() override;

    void invalidate();

    QString name();

    ModuleType type();

    virtual Module *clone() = 0;

protected:

    void registerInput(Input *);
    void unregisterInput(Input *);

    void registerOutput(Output *);
    void unregisterOutput(Output *);

    virtual void run() = 0;

    QVBoxLayout *contentLayout;

private:

    void disconnectInputs();
    void disconnectOutputs();

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    QList<Input *>  *inputs;
    QList<Output *> *outputs;

    QLabel      *moduleLabel;

    QHBoxLayout *mainLayout;

    QVBoxLayout *inputLayout;
    QVBoxLayout *outputLayout;

    QString m_Name;

    ModuleType m_Type;

    bool isBeingDragged = false;

signals:

public slots:

    void onDataReady();

};

#endif // MODULE_H
