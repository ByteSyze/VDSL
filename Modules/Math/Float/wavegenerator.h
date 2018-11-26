#ifndef WAVEGENERATOR_H
#define WAVEGENERATOR_H

#include <QTime>
#include <Modules/module.h>
#include <Ports/floatinput.h>
#include <Ports/floatoutput.h>

class WaveGenerator : public Module
{
    Q_OBJECT
public:
    explicit WaveGenerator(QWidget *parent = nullptr);
    ~WaveGenerator();

    void run();

private:

    FloatOutput *out;

    float angle           = 0.00;
    float angularVelocity = 0.25;

    static QTime generatorTime;

};

#endif // WAVEGENERATOR_H
