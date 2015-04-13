#ifndef MRB_PINNAME_H
#define MRB_PINNAME_H

#ifdef __cplusplus
extern "C" {
#endif

#include "mruby.h"

extern void mrb_mbed_pinname_define(mrb_state *mrb, struct RClass *mrb_mbed);

#ifdef __cplusplus
}
#endif

#endif
