#include "mbed.h"
#include "mrbTimer.h"

static struct mrb_data_type mbed_timer_type = {
    "Timer", mrb_mbed_timer_free
};

mrb_value
mrb_mbed_timer_init(mrb_state *mrb, mrb_value self)
{
    DATA_TYPE(self) = &mbed_timer_type;
    DATA_PTR(self) = new Timer();

    return self;
}

void
mrb_mbed_timer_free(mrb_state *mrb, void *ptr)
{
    Timer *obj = static_cast<Timer*>(ptr);
    delete obj;
}

mrb_value
mrb_mbed_timer_start(mrb_state *mrb, mrb_value self)
{
    Timer *obj = static_cast<Timer*>(DATA_PTR(self));
    obj->start();

    return self;
}

mrb_value
mrb_mbed_timer_stop(mrb_state *mrb, mrb_value self)
{
    Timer *obj = static_cast<Timer*>(DATA_PTR(self));
    obj->stop();

    return self;
}

mrb_value
mrb_mbed_timer_reset(mrb_state *mrb, mrb_value self)
{
    Timer *obj = static_cast<Timer*>(DATA_PTR(self));
    obj->reset();

    return self;
}

mrb_value
mrb_mbed_timer_read(mrb_state *mrb, mrb_value self)
{
    Timer *obj = static_cast<Timer*>(DATA_PTR(self));

    return mrb_float_value(mrb, obj->read());
}

mrb_value
mrb_mbed_timer_read_ms(mrb_state *mrb, mrb_value self)
{
    Timer *obj = static_cast<Timer*>(DATA_PTR(self));

    return mrb_fixnum_value(obj->read_ms());
}

mrb_value
mrb_mbed_timer_read_us(mrb_state *mrb, mrb_value self)
{
    Timer *obj = static_cast<Timer*>(DATA_PTR(self));

    return mrb_fixnum_value(obj->read_us());
}
