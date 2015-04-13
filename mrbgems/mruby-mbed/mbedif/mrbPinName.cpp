
#include "mbed.h"
#include "PinNames.h"

#include "mrbPinName.h"

void
mrb_mbed_pinname_define(mrb_state *mrb, struct RClass *mrb_mbed)
{
    mrb_define_const(mrb,   mrb_mbed,   "LED1",         mrb_fixnum_value(LED1));
    mrb_define_const(mrb,   mrb_mbed,   "LED2",         mrb_fixnum_value(LED2));
    mrb_define_const(mrb,   mrb_mbed,   "LED_RED",      mrb_fixnum_value(LED_RED));
    mrb_define_const(mrb,   mrb_mbed,   "LED_GREEN",    mrb_fixnum_value(LED_GREEN));
    mrb_define_const(mrb,   mrb_mbed,   "LED_BLUE",     mrb_fixnum_value(LED_BLUE));
    mrb_define_const(mrb,   mrb_mbed,   "I2C_SCL",      mrb_fixnum_value(I2C_SCL));
    mrb_define_const(mrb,   mrb_mbed,   "I2C_SDA",      mrb_fixnum_value(I2C_SDA));

#if defined(TARGET_MBED_MBRZA1H)
    mrb_define_const(mrb,   mrb_mbed,   "LED3",         mrb_fixnum_value(LED3));
    mrb_define_const(mrb,   mrb_mbed,   "LED4",         mrb_fixnum_value(LED4));
    mrb_define_const(mrb,   mrb_mbed,   "LED_USER",     mrb_fixnum_value(LED_USER));
#endif

}
