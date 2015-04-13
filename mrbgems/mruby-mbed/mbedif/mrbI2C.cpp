#include "mbed.h"
#include "mrbI2C.h"

static struct mrb_data_type mbed_i2c_type = {
    "I2C", mrb_mbed_i2c_free
};

mrb_value
mrb_mbed_i2c_init(mrb_state *mrb, mrb_value self)
{
    mrb_int sda, scl;

    mrb_get_args(mrb, "ii", &sda, &scl);
    PinName pin_sda = static_cast<PinName>(sda);
    PinName pin_scl = static_cast<PinName>(scl);

    DATA_TYPE(self) = &mbed_i2c_type;
    DATA_PTR(self) = new I2C(pin_sda, pin_scl);

    return self;
}

void
mrb_mbed_i2c_free(mrb_state *mrb, void *ptr)
{
    I2C *obj = static_cast<I2C*>(ptr);
    delete obj;
}

mrb_value
mrb_mbed_i2c_freq(mrb_state *mrb, mrb_value self)
{
    I2C *obj = static_cast<I2C*>(DATA_PTR(self));

    mrb_int freq;
    mrb_get_args(mrb, "i", &freq);

    obj->frequency(freq);

    return self;
}

mrb_value
mrb_mbed_i2c_start(mrb_state *mrb, mrb_value self)
{
    I2C *obj = static_cast<I2C*>(DATA_PTR(self));

    obj->start();

    return self;
}

mrb_value
mrb_mbed_i2c_stop(mrb_state *mrb, mrb_value self)
{
    I2C *obj = static_cast<I2C*>(DATA_PTR(self));

    obj->stop();

    return self;
}
