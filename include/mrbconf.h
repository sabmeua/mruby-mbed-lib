/*
** mrbconf.h - mruby core configuration
**
** See Copyright Notice in mruby.h
*/

#ifndef MRUBYCONF_H
#define MRUBYCONF_H

/* configuration options: */
/* add -DMRB_USE_FLOAT to use float instead of double for floating point numbers */
//#define MRB_USE_FLOAT

/* add -DMRB_INT16 to use 16bit integer for mrb_int; conflict with MRB_INT64 */
//#define MRB_INT16

/* add -DMRB_INT64 to use 64bit integer for mrb_int; conflict with MRB_INT16 */
//#define MRB_INT64

/* represent mrb_value in boxed double; conflict with MRB_USE_FLOAT */
//#define MRB_NAN_BOXING

/* define on big endian machines; used by MRB_NAN_BOXING */
//#define MRB_ENDIAN_BIG

/* represent mrb_value as a word (natural unit of data for the processor) */
//#define MRB_WORD_BOXING

/* argv max size in mrb_funcall */
//#define MRB_FUNCALL_ARGC_MAX 16

/* number of object per heap page */
//#define MRB_HEAP_PAGE_SIZE 1024

/* use segmented list for IV table */
//#define MRB_USE_IV_SEGLIST

/* initial size for IV khash; ignored when MRB_USE_IV_SEGLIST is set */
//#define MRB_IVHASH_INIT_SIZE 8

/* if _etext and _edata available, mruby can reduce memory used by symbols */
//#define MRB_USE_ETEXT_EDATA

/* do not use __init_array_start to determine readonly data section;
   effective only when MRB_USE_ETEXT_EDATA is defined */
//#define MRB_NO_INIT_ARRAY_START

/* turn off generational GC by default */
//#define MRB_GC_TURN_OFF_GENERATIONAL

/* default size of khash table bucket */
//#define KHASH_DEFAULT_SIZE 32

/* allocated memory address alignment */
//#define POOL_ALIGNMENT 4

/* page size of memory pool */
//#define POOL_PAGE_SIZE 16000

/* initial minimum size for string buffer */
//#define MRB_STR_BUF_MIN_SIZE 128

/* arena size */
//#define MRB_GC_ARENA_SIZE 100

/* fixed size GC arena */
//#define MRB_GC_FIXED_ARENA

/* state atexit stack size */
//#define MRB_FIXED_STATE_ATEXIT_STACK_SIZE 5

/* fixed size state atexit stack */
//#define MRB_FIXED_STATE_ATEXIT_STACK

/* -DDISABLE_XXXX to drop following features */
//#define DISABLE_STDIO		/* use of stdio */

/* -DENABLE_XXXX to enable following features */
//#define ENABLE_DEBUG		/* hooks for debugger */

/* end of configuration */

/* define ENABLE_XXXX from DISABLE_XXX */
#ifndef DISABLE_STDIO
#define ENABLE_STDIO
#endif
#ifndef ENABLE_DEBUG
#define DISABLE_DEBUG
#endif

#ifdef ENABLE_STDIO
# include <stdio.h>
#endif

#ifndef FALSE
# define FALSE 0
#endif

#ifndef TRUE
# define TRUE 1
#endif

#if defined(MRB_BUILD_AS_DLL)

#if defined(MRB_CORE) || defined(MRB_LIB)
#define MRB_API __declspec(dllexport)
#else
#define MRB_API __declspec(dllimport)
#endif
#else
#define MRB_API extern
#endif

#endif  /* MRUBYCONF_H */

