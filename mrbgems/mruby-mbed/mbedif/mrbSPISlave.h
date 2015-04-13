#ifndef MRB_SPISLAVE_H
#define MRB_SPISLAVE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "mruby.h"
#include "mruby/data.h"

extern mrb_value mrb_mbed_spis_init(mrb_state *mrb, mrb_value self);
extern void mrb_mbed_spis_free(mrb_state *mrb, void *ptr);
extern mrb_value mrb_mbed_spis_format(mrb_state *mrb, mrb_value self);
extern mrb_value mrb_mbed_spis_freq(mrb_state *mrb, mrb_value self);
extern mrb_value mrb_mbed_spis_write(mrb_state *mrb, mrb_value self);
extern mrb_value mrb_mbed_spis_reply(mrb_state *mrb, mrb_value self);
extern mrb_value mrb_mbed_spis_read(mrb_state *mrb, mrb_value self);
extern mrb_value mrb_mbed_spis_receive(mrb_state *mrb, mrb_value self);

#ifdef __cplusplus
}
#endif

#endif
