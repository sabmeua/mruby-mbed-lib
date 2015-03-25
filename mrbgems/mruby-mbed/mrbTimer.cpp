#include "mbed.h"
#include "mrbTimer.h"

void *
newTimer()
{
    return static_cast<void*>(new Timer());
}

void
delTimer(void *ptr)
{
    Timer *obj = static_cast<Timer*>(ptr);
    delete obj;
}

void
startTimer(void *ptr)
{
    Timer *obj = static_cast<Timer*>(ptr);
    obj->start();
}

void
stopTimer(void *ptr)
{
    Timer *obj = static_cast<Timer*>(ptr);
    obj->stop();
}

void
resetTimer(void *ptr)
{
    Timer *obj = static_cast<Timer*>(ptr);
    obj->reset();
}

float
readTimer(void *ptr)
{
    Timer *obj = static_cast<Timer*>(ptr);
    return obj->read();
}

int
readMSTimer(void *ptr)
{
    Timer *obj = static_cast<Timer*>(ptr);
    return obj->read_ms();
}

int
readUSTimer(void *ptr)
{
    Timer *obj = static_cast<Timer*>(ptr);
    return obj->read_us();
}


