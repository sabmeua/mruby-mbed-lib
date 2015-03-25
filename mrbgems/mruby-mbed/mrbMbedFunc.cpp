#include "mbed.h"
#include "mrbMbedFunc.h"

void
mbedSleep(int t)
{
    wait((float)t);
}

void
mbedSleepMS(int t)
{
    wait_ms(t);
}

void
mbedSleepUS(int t)
{
    wait_us(t);
}
