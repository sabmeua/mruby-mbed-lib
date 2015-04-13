#ifndef MRB_TIMER_H
#define MRB_TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "mruby.h"
#include "mruby/data.h"

extern mrb_value mrb_mbed_timer_init(mrb_state *mrb, mrb_value self);
extern void mrb_mbed_timer_free(mrb_state *mrb, void *ptr);
extern mrb_value mrb_mbed_timer_start(mrb_state *mrb, mrb_value self);
extern mrb_value mrb_mbed_timer_stop(mrb_state *mrb, mrb_value self);
extern mrb_value mrb_mbed_timer_reset(mrb_state *mrb, mrb_value self);
extern mrb_value mrb_mbed_timer_read(mrb_state *mrb, mrb_value self);
extern mrb_value mrb_mbed_timer_read_ms(mrb_state *mrb, mrb_value self);
extern mrb_value mrb_mbed_timer_read_us(mrb_state *mrb, mrb_value self);

#ifdef __cplusplus
}
#endif

#endif
