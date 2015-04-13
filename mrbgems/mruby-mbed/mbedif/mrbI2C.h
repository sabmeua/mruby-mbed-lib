#ifndef MRB_I2C_H
#define MRB_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include "mruby.h"
#include "mruby/data.h"

extern mrb_value mrb_mbed_i2c_init(mrb_state *mrb, mrb_value self);
extern void mrb_mbed_i2c_free(mrb_state *mrb, void *ptr);
extern mrb_value mrb_mbed_i2c_freq(mrb_state *mrb, mrb_value self);
extern mrb_value mrb_mbed_i2c_start(mrb_state *mrb, mrb_value self);
extern mrb_value mrb_mbed_i2c_stop(mrb_state *mrb, mrb_value self);

#ifdef __cplusplus
}
#endif

#endif
