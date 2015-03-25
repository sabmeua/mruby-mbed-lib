#include "mbed.h"
#include "mrbDigitalOut.h"

void *
newDigitalOut(int pin)
{
    PinName pinname = static_cast<PinName>(pin);
    return static_cast<void*>(new DigitalOut(pinname));
}

void
delDigitalOut(void *ptr)
{
    DigitalOut *obj = static_cast<DigitalOut*>(ptr);
    delete obj;
}

void
writeDigitalOut(void *ptr, int val)
{
    DigitalOut *obj = static_cast<DigitalOut*>(ptr);
    obj->write(val);
}

int
readDigitalOut(void *ptr)
{
    DigitalOut *obj = static_cast<DigitalOut*>(ptr);
    return obj->read();
}
