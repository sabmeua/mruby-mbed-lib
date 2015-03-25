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

/**
 * mbed
 */
static mrb_value
mrb_mbed_sleep(mrb_state *mrb, mrb_value obj)
{
    mrb_int t;
    mrb_get_args(mrb, "i", &t);
    mbedSleep(t);

    return obj;
}

static mrb_value
mrb_mbed_sleep_ms(mrb_state *mrb, mrb_value obj)
{
    mrb_int t;
    mrb_get_args(mrb, "i", &t);
    mbedSleepMS(t);

    return obj;
}

static mrb_value
mrb_mbed_sleep_us(mrb_state *mrb, mrb_value obj)
{
    mrb_int t;
    mrb_get_args(mrb, "i", &t);
    mbedSleepUS(t);

    return obj;
}

/**
 * mbed::I2C
 */


/**
 * mbed::DigitalOut
 */
static void mbed_do_free(mrb_state *mrb, void *ptr) {
    delDigitalOut(ptr);
}

static struct mrb_data_type mbed_do_type = {
    "DigitalOut", mbed_do_free
};

static mrb_value
mrb_mbed_do_init(mrb_state *mrb, mrb_value self)
{
    mrb_int pin;
    mrb_get_args(mrb, "i", &pin);

    DATA_TYPE(self) = &mbed_do_type;
    DATA_PTR(self) = newDigitalOut(pin);

    return self;
}

static mrb_value
mrb_mbed_do_write(mrb_state *mrb, mrb_value self)
{
    void *do_obj = DATA_PTR(self);

    mrb_int val;
    mrb_get_args(mrb, "i", &val);

    writeDigitalOut(do_obj, val);

    return self;
}

static mrb_value
mrb_mbed_do_read(mrb_state *mrb, mrb_value self)
{
    void *do_obj = DATA_PTR(self);

    return mrb_fixnum_value(readDigitalOut(do_obj));
}

/**
 * mbed::Timer
 */
static void mbed_timer_free(mrb_state *mrb, void *ptr) {
    delTimer(ptr);
}

static struct mrb_data_type mbed_timer_type = {
    "Timer", mbed_timer_free
};

static mrb_value
mrb_mbed_timer_init(mrb_state *mrb, mrb_value self)
{
    void *timer_obj;

    DATA_TYPE(self) = &mbed_timer_type;
    DATA_PTR(self) = newTimer();

    return self;
}

static mrb_value
mrb_mbed_timer_start(mrb_state *mrb, mrb_value self)
{
    void *timer_obj = DATA_PTR(self);

    startTimer(timer_obj);

    return self;
}

static mrb_value
mrb_mbed_timer_stop(mrb_state *mrb, mrb_value self)
{
    void *timer_obj = DATA_PTR(self);

    stopTimer(timer_obj);

    return self;
}

static mrb_value
mrb_mbed_timer_reset(mrb_state *mrb, mrb_value self)
{
    void *timer_obj = DATA_PTR(self);

    resetTimer(timer_obj);

    return self;
}

static mrb_value
mrb_mbed_timer_read(mrb_state *mrb, mrb_value self)
{
    void *timer_obj = DATA_PTR(self);

    return mrb_float_value(mrb, readTimer(timer_obj));
}

static mrb_value
mrb_mbed_timer_read_ms(mrb_state *mrb, mrb_value self)
{
    void *timer_obj = DATA_PTR(self);

    return mrb_fixnum_value(readMSTimer(timer_obj));
}

static mrb_value
mrb_mbed_timer_read_us(mrb_state *mrb, mrb_value self)
{
    void *timer_obj = DATA_PTR(self);

    return mrb_fixnum_value(readUSTimer(timer_obj));
}

/* ------------------------------------------------------------------------*/
void
mrb_mruby_mbed_gem_init(mrb_state* mrb)
{
    struct RClass *mrb_mbed;
    struct RClass *mrb_mbed_do;
    struct RClass *mrb_mbed_timer;

    mrb_mbed = mrb_define_module(mrb, "Mbed");
    mrb_define_const(mrb,   mrb_mbed,   "LED1",         mrb_fixnum_value(LED1));
    mrb_define_const(mrb,   mrb_mbed,   "LED2",         mrb_fixnum_value(LED2));
    mrb_define_const(mrb,   mrb_mbed,   "LED3",         mrb_fixnum_value(LED3));
    mrb_define_const(mrb,   mrb_mbed,   "LED4",         mrb_fixnum_value(LED4));
    mrb_define_const(mrb,   mrb_mbed,   "LED_RED",      mrb_fixnum_value(LED_RED));
    mrb_define_const(mrb,   mrb_mbed,   "LED_GREEN",    mrb_fixnum_value(LED_GREEN));
    mrb_define_const(mrb,   mrb_mbed,   "LED_BLUE",     mrb_fixnum_value(LED_BLUE));
    mrb_define_const(mrb,   mrb_mbed,   "LED_USER",     mrb_fixnum_value(LED_USER));
    mrb_define_module_function(mrb, mrb_mbed,   "sleep",    mrb_mbed_sleep, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, mrb_mbed,   "sleep_ms", mrb_mbed_sleep, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, mrb_mbed,   "sleep_us", mrb_mbed_sleep, MRB_ARGS_REQ(1));
    
    mrb_mbed_do = mrb_define_class_under(mrb, mrb_mbed, "DigitalOut", mrb->object_class);
    mrb_define_method(mrb,  mrb_mbed_do,    "initialize",   mrb_mbed_do_init,       MRB_ARGS_REQ(1));
    mrb_define_method(mrb,  mrb_mbed_do,    "write",        mrb_mbed_do_write,      MRB_ARGS_REQ(1));
    mrb_define_method(mrb,  mrb_mbed_do,    "read",         mrb_mbed_do_read,       MRB_ARGS_NONE());

    mrb_mbed_timer = mrb_define_class_under(mrb, mrb_mbed, "Timer", mrb->object_class);
    mrb_define_method(mrb,  mrb_mbed_timer, "initialize",   mrb_mbed_timer_init,    MRB_ARGS_NONE());
    mrb_define_method(mrb,  mrb_mbed_timer, "start",        mrb_mbed_timer_start,   MRB_ARGS_NONE());
    mrb_define_method(mrb,  mrb_mbed_timer, "stop",         mrb_mbed_timer_stop,    MRB_ARGS_NONE());
    mrb_define_method(mrb,  mrb_mbed_timer, "reset",        mrb_mbed_timer_reset,   MRB_ARGS_NONE());
    mrb_define_method(mrb,  mrb_mbed_timer, "read",         mrb_mbed_timer_read,    MRB_ARGS_NONE());
    mrb_define_method(mrb,  mrb_mbed_timer, "read_ms",      mrb_mbed_timer_read_ms, MRB_ARGS_NONE());
    mrb_define_method(mrb,  mrb_mbed_timer, "read_us",      mrb_mbed_timer_read_us, MRB_ARGS_NONE());
}

void
mrb_mruby_mbed_gem_final(mrb_state* mrb)
{
}
