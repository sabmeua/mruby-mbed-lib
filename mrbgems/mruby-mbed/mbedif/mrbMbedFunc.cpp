#include "mbed.h"
#include "mrbMbedFunc.h"

mrb_value
mrb_mbed_sleep(mrb_state *mrb, mrb_value obj)
{
    mrb_int t;
    mrb_get_args(mrb, "i", &t);
    wait((float)t);

    return obj;
}

mrb_value
mrb_mbed_sleep_ms(mrb_state *mrb, mrb_value obj)
{
    mrb_int t;
    mrb_get_args(mrb, "i", &t);
    wait_ms(t);

    return obj;
}

mrb_value
mrb_mbed_sleep_us(mrb_state *mrb, mrb_value obj)
{
    mrb_int t;
    mrb_get_args(mrb, "i", &t);
    wait_us(t);

    return obj;
}
