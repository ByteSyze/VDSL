#include "wavegenerator.h"

WaveGenerator::WaveGenerator(QWidget *parent) : Module("Wave Generator", parent, ModuleType::emitter)
{
    out = new FloatOutput;
    out->setName("Output");

    registerOutput(out);
}

WaveGenerator::~WaveGenerator()
{

}

void WaveGenerator::run()
{
    angle += angularVelocity;
    out->send(sin(angle));
}

Module *WaveGenerator::clone()
{
    return new WaveGenerator;
}
