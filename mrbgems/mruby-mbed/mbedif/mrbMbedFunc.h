#ifndef MRB_MBEDFUNC_H
#define MRB_MBEDFUNC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "mruby.h"

extern mrb_value mrb_mbed_sleep(mrb_state *mrb, mrb_value obj);
extern mrb_value mrb_mbed_sleep_ms(mrb_state *mrb, mrb_value obj);
extern mrb_value mrb_mbed_sleep_us(mrb_state *mrb, mrb_value obj);

#ifdef __cplusplus
}
#endif

#endif
