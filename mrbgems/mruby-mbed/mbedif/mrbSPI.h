#ifndef MRB_SPI_H
#define MRB_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "mruby.h"
#include "mruby/data.h"

extern mrb_value mrb_mbed_spi_init(mrb_state *mrb, mrb_value self);
extern void mrb_mbed_spi_free(mrb_state *mrb, void *ptr);
extern mrb_value mrb_mbed_spi_format(mrb_state *mrb, mrb_value self);
extern mrb_value mrb_mbed_spi_freq(mrb_state *mrb, mrb_value self);
extern mrb_value mrb_mbed_spi_write(mrb_state *mrb, mrb_value self);

#ifdef __cplusplus
}
#endif

#endif
