#include "mbed.h"
#include "mrbSPISlave.h"

static struct mrb_data_type mbed_spis_type = {
    "SPISlave", mrb_mbed_spis_free
};

mrb_value
mrb_mbed_spis_init(mrb_state *mrb, mrb_value self)
{
    mrb_int mosi, miso, sclk, ssel;

    mrb_get_args(mrb, "iiii", &mosi, &miso, &sclk, &ssel);
    PinName pin_mosi = static_cast<PinName>(mosi);
    PinName pin_miso = static_cast<PinName>(miso);
    PinName pin_sclk = static_cast<PinName>(sclk);
    PinName pin_ssel = static_cast<PinName>(ssel);

    DATA_TYPE(self) = &mbed_spis_type;
    DATA_PTR(self) = new SPISlave(pin_mosi, pin_miso, pin_sclk, pin_ssel);

    return self;
}

void
mrb_mbed_spis_free(mrb_state *mrb, void *ptr)
{
    SPISlave *obj = static_cast<SPISlave*>(ptr);
    delete obj;
}

mrb_value
mrb_mbed_spis_freq(mrb_state *mrb, mrb_value self)
{
    SPISlave *obj = static_cast<SPISlave*>(DATA_PTR(self));

    mrb_int freq;
    if (mrb_get_args(mrb, "|i", &freq) == 0) {
        obj->frequency();
    } else {
        obj->frequency(freq);
    }

    return self;
}

mrb_value
mrb_mbed_spis_format(mrb_state *mrb, mrb_value self)
{
    SPISlave *obj = static_cast<SPISlave*>(DATA_PTR(self));

    mrb_int bits, mode;
    if (mrb_get_args(mrb, "i|i", &bits, &mode) == 1) {
        obj->format(bits);
    } else {
        obj->format(bits, mode);    
    }

    return self;
}

mrb_value
mrb_mbed_spis_reply(mrb_state *mrb, mrb_value self)
{
    SPISlave *obj = static_cast<SPISlave*>(DATA_PTR(self));

    mrb_int value;
    mrb_get_args(mrb, "i", &value);
    obj->reply(value);

    return self;
}

mrb_value
mrb_mbed_spis_read(mrb_state *mrb, mrb_value self)
{
    SPISlave *obj = static_cast<SPISlave*>(DATA_PTR(self));

    return mrb_fixnum_value(obj->read());
}

mrb_value
mrb_mbed_spis_receive(mrb_state *mrb, mrb_value self)
{
    SPISlave *obj = static_cast<SPISlave*>(DATA_PTR(self));

    mrb_value blk;
    mrb_get_args(mrb, "&", &blk);
    if (mrb_nil_p(blk)) {
        mrb_raise(mrb, E_ARGUMENT_ERROR, "without a block");
    } else {
        while (obj->receive()) {
            mrb_value ret = mrb_yield(mrb, blk, mrb_nil_value());
            if (mrb_fixnum(ret)!= 0) {
                break;
            } 
        }
    }
    return self;
}
