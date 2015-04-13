#ifndef MRB_DIGITALOUT_H
#define MRB_DIGITALOUT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "mruby.h"
#include "mruby/data.h"

extern mrb_value mrb_mbed_do_init(mrb_state *mrb, mrb_value self);
extern void mrb_mbed_do_free(mrb_state *mrb, void *ptr);
extern mrb_value mrb_mbed_do_write(mrb_state *mrb, mrb_value self);
extern mrb_value mrb_mbed_do_read(mrb_state *mrb, mrb_value self);
extern mrb_value mrb_mbed_do_high(mrb_state *mrb, mrb_value self);
extern mrb_value mrb_mbed_do_low(mrb_state *mrb, mrb_value self);

#ifdef __cplusplus
}
#endif

#endif
