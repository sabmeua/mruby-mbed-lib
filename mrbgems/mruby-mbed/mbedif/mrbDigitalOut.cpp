#include "mbed.h"
#include "mrbDigitalOut.h"

static struct mrb_data_type mbed_do_type = {
    "DigitalOut", mrb_mbed_do_free
};

mrb_value
mrb_mbed_do_init(mrb_state *mrb, mrb_value self)
{
    mrb_int pin;
    mrb_get_args(mrb, "i", &pin);
    PinName pinname = static_cast<PinName>(pin);

    DATA_TYPE(self) = &mbed_do_type;
    DATA_PTR(self) = new DigitalOut(pinname);

    return self;
}

void
mrb_mbed_do_free(mrb_state *mrb, void *ptr)
{
    DigitalOut *obj = static_cast<DigitalOut*>(ptr);
    delete obj;
}

mrb_value
mrb_mbed_do_write(mrb_state *mrb, mrb_value self)
{
    DigitalOut *obj = static_cast<DigitalOut*>(DATA_PTR(self));

    mrb_int val;
    mrb_get_args(mrb, "i", &val);

    obj->write(val);

    return self;
}

mrb_value
mrb_mbed_do_read(mrb_state *mrb, mrb_value self)
{
    DigitalOut *obj = static_cast<DigitalOut*>(DATA_PTR(self));

    return mrb_fixnum_value(obj->read());
}

mrb_value
mrb_mbed_do_high(mrb_state *mrb, mrb_value self)
{
    DigitalOut *obj = static_cast<DigitalOut*>(DATA_PTR(self));

    obj->write(1);
}

mrb_value
mrb_mbed_do_low(mrb_state *mrb, mrb_value self)
{
    DigitalOut *obj = static_cast<DigitalOut*>(DATA_PTR(self));

    obj->write(0);
}
