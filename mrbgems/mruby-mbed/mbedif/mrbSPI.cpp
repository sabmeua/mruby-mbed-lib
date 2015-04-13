#include "mbed.h"
#include "mrbSPI.h"

static struct mrb_data_type mbed_spi_type = {
    "SPI", mrb_mbed_spi_free
};

mrb_value
mrb_mbed_spi_init(mrb_state *mrb, mrb_value self)
{
    mrb_int mosi, miso, sclk;

    mrb_get_args(mrb, "iii", &mosi, &miso, &sclk);
    PinName pin_mosi = static_cast<PinName>(mosi);
    PinName pin_miso = static_cast<PinName>(miso);
    PinName pin_sclk = static_cast<PinName>(sclk);

    DATA_TYPE(self) = &mbed_spi_type;
    DATA_PTR(self) = new SPI(pin_mosi, pin_miso, pin_sclk);

    return self;
}

void
mrb_mbed_spi_free(mrb_state *mrb, void *ptr)
{
    SPI *obj = static_cast<SPI*>(ptr);
    delete obj;
}

mrb_value
mrb_mbed_spi_freq(mrb_state *mrb, mrb_value self)
{
    SPI *obj = static_cast<SPI*>(DATA_PTR(self));

    mrb_int freq;
    if (mrb_get_args(mrb, "|i", &freq) == 0) {
        obj->frequency();
    } else {
        obj->frequency(freq);
    }

    return self;
}

mrb_value
mrb_mbed_spi_format(mrb_state *mrb, mrb_value self)
{
    SPI *obj = static_cast<SPI*>(DATA_PTR(self));

    mrb_int bits, mode;
    if (mrb_get_args(mrb, "i|i", &bits, &mode) == 1) {
        obj->format(bits);
    } else {
        obj->format(bits, mode);    
    }

    return self;
}

mrb_value
mrb_mbed_spi_write(mrb_state *mrb, mrb_value self)
{
    SPI *obj = static_cast<SPI*>(DATA_PTR(self));

    mrb_int value;
    mrb_get_args(mrb, "i", &value);
    obj->write(value);

    return self;
}