/*
** mbed.c - mbed module
**
*/
#include "mruby.h"
#include "mruby/data.h"

#include "mrbPinName.h"
#include "mrbDigitalOut.h"
#include "mrbTimer.h"
#include "mrbMbedFunc.h"
#include "mrbI2C.h"
#include "mrbSPI.h"
#include "mrbSPISlave.h"

void
mrb_mruby_mbed_gem_init(mrb_state* mrb)
{
    struct RClass *mrb_mbed;
    struct RClass *mrb_mbed_do;
    struct RClass *mrb_mbed_timer;
    struct RClass *mrb_mbed_i2c;
    struct RClass *mrb_mbed_spi;
    struct RClass *mrb_mbed_spis;

    mrb_mbed = mrb_define_module(mrb, "Mbed");
    
    mrb_mbed_pinname_define(mrb, mrb_mbed);

    mrb_define_module_function(mrb, mrb_mbed,   "sleep",    mrb_mbed_sleep,         MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, mrb_mbed,   "wait",     mrb_mbed_sleep,         MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, mrb_mbed,   "sleep_ms", mrb_mbed_sleep_ms,      MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, mrb_mbed,   "wait_ms",  mrb_mbed_sleep_ms,      MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, mrb_mbed,   "sleep_us", mrb_mbed_sleep_us,      MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, mrb_mbed,   "wait_us",  mrb_mbed_sleep_us,      MRB_ARGS_REQ(1));
    
    mrb_mbed_do = mrb_define_class_under(mrb, mrb_mbed, "DigitalOut", mrb->object_class);
    mrb_define_method(mrb,  mrb_mbed_do,    "initialize",   mrb_mbed_do_init,       MRB_ARGS_REQ(1));
    mrb_define_method(mrb,  mrb_mbed_do,    "write",        mrb_mbed_do_write,      MRB_ARGS_REQ(1));
    mrb_define_method(mrb,  mrb_mbed_do,    "read",         mrb_mbed_do_read,       MRB_ARGS_NONE());
    mrb_define_method(mrb,  mrb_mbed_do,    "high",         mrb_mbed_do_high,       MRB_ARGS_NONE());
    mrb_define_method(mrb,  mrb_mbed_do,    "low",          mrb_mbed_do_low,        MRB_ARGS_NONE());

    mrb_mbed_timer = mrb_define_class_under(mrb, mrb_mbed, "Timer", mrb->object_class);
    mrb_define_method(mrb,  mrb_mbed_timer, "initialize",   mrb_mbed_timer_init,    MRB_ARGS_NONE());
    mrb_define_method(mrb,  mrb_mbed_timer, "start",        mrb_mbed_timer_start,   MRB_ARGS_NONE());
    mrb_define_method(mrb,  mrb_mbed_timer, "stop",         mrb_mbed_timer_stop,    MRB_ARGS_NONE());
    mrb_define_method(mrb,  mrb_mbed_timer, "reset",        mrb_mbed_timer_reset,   MRB_ARGS_NONE());
    mrb_define_method(mrb,  mrb_mbed_timer, "read",         mrb_mbed_timer_read,    MRB_ARGS_NONE());
    mrb_define_method(mrb,  mrb_mbed_timer, "read_ms",      mrb_mbed_timer_read_ms, MRB_ARGS_NONE());
    mrb_define_method(mrb,  mrb_mbed_timer, "read_us",      mrb_mbed_timer_read_us, MRB_ARGS_NONE());
    
    mrb_mbed_i2c = mrb_define_class_under(mrb, mrb_mbed, "I2C", mrb->object_class);
    mrb_define_method(mrb,  mrb_mbed_i2c,   "initialize",   mrb_mbed_i2c_init,      MRB_ARGS_REQ(2));
    mrb_define_method(mrb,  mrb_mbed_i2c,   "frequency",    mrb_mbed_i2c_freq,      MRB_ARGS_REQ(1));
    //mrb_define_method(mrb,  mrb_mbed_i2c,   "read",         mrb_mbed_i2c_read,      MRB_ARGS_REQ(1)|MRB_ARGS_OPT(3));
    //mrb_define_method(mrb,  mrb_mbed_i2c,   "write",        mrb_mbed_i2c_write,     MRB_ARGS_REQ(1)|MRB_ARGS_OPT(3));    
    mrb_define_method(mrb,  mrb_mbed_i2c,   "start",        mrb_mbed_i2c_start,     MRB_ARGS_NONE());    
    mrb_define_method(mrb,  mrb_mbed_i2c,   "stop",         mrb_mbed_i2c_stop,      MRB_ARGS_NONE());    

    mrb_mbed_spi = mrb_define_class_under(mrb, mrb_mbed, "SPI", mrb->object_class);
    mrb_define_method(mrb,  mrb_mbed_spi,   "initialize",   mrb_mbed_spi_init,      MRB_ARGS_REQ(3));
    mrb_define_method(mrb,  mrb_mbed_spi,   "frequency",    mrb_mbed_spi_freq,      MRB_ARGS_OPT(1));
    mrb_define_method(mrb,  mrb_mbed_spi,   "format",       mrb_mbed_spi_format,    MRB_ARGS_REQ(1)|MRB_ARGS_OPT(1));
    mrb_define_method(mrb,  mrb_mbed_spi,   "write",        mrb_mbed_spi_write,     MRB_ARGS_REQ(1));

    mrb_mbed_spis = mrb_define_class_under(mrb, mrb_mbed, "SPISlave", mrb->object_class);
    mrb_define_method(mrb,  mrb_mbed_spis,  "initialize",   mrb_mbed_spis_init,     MRB_ARGS_REQ(4));
    mrb_define_method(mrb,  mrb_mbed_spis,  "frequency",    mrb_mbed_spis_freq,     MRB_ARGS_OPT(1));
    mrb_define_method(mrb,  mrb_mbed_spis,  "format",       mrb_mbed_spis_format,   MRB_ARGS_REQ(1)|MRB_ARGS_OPT(1));
    mrb_define_method(mrb,  mrb_mbed_spis,  "reply",        mrb_mbed_spis_reply,    MRB_ARGS_REQ(1));
    mrb_define_method(mrb,  mrb_mbed_spis,  "read",         mrb_mbed_spis_read,     MRB_ARGS_NONE());
    mrb_define_method(mrb,  mrb_mbed_spis,  "receive",      mrb_mbed_spis_receive,  MRB_ARGS_NONE());

}

void
mrb_mruby_mbed_gem_final(mrb_state* mrb)
{
}
