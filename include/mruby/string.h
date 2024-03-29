/*
** mruby/string.h - String class
**
** See Copyright Notice in mruby.h
*/

#ifndef MRUBY_STRING_H
#define MRUBY_STRING_H

#if defined(__cplusplus)
extern "C" {
#endif

extern const char mrb_digitmap[];

#define RSTRING_EMBED_LEN_MAX ((mrb_int)(sizeof(void*) * 3 - 1))

struct RString {
  MRB_OBJECT_HEADER;
  union {
    struct {
      mrb_int len;
      union {
        mrb_int capa;
        struct mrb_shared_string *shared;
      } aux;
      char *ptr;
    } heap;
    char ary[RSTRING_EMBED_LEN_MAX + 1];
  } as;
};

#define RSTR_EMBED_P(s) ((s)->flags & MRB_STR_EMBED)
#define RSTR_SET_EMBED_FLAG(s) ((s)->flags |= MRB_STR_EMBED)
#define RSTR_UNSET_EMBED_FLAG(s) ((s)->flags &= ~(MRB_STR_EMBED|MRB_STR_EMBED_LEN_MASK))
#define RSTR_SET_EMBED_LEN(s, n) do {\
  size_t tmp_n = (n);\
  s->flags &= ~MRB_STR_EMBED_LEN_MASK;\
  s->flags |= (tmp_n) << MRB_STR_EMBED_LEN_SHIFT;\
} while (0)
#define RSTR_SET_LEN(s, n) do {\
  if (RSTR_EMBED_P(s)) {\
    RSTR_SET_EMBED_LEN((s),(n));\
  } else {\
    s->as.heap.len = (mrb_int)(n);\
  }\
} while (0)
#define RSTR_EMBED_LEN(s)\
  (mrb_int)(((s)->flags & MRB_STR_EMBED_LEN_MASK) >> MRB_STR_EMBED_LEN_SHIFT)
#define RSTR_PTR(s) ((RSTR_EMBED_P(s)) ? (s)->as.ary : (s)->as.heap.ptr)
#define RSTR_LEN(s) ((RSTR_EMBED_P(s)) ? RSTR_EMBED_LEN(s) : (s)->as.heap.len)
#define RSTR_CAPA(s) (RSTR_EMBED_P(s) ? RSTRING_EMBED_LEN_MAX : (s)->as.heap.aux.capa)

#define RSTR_SHARED_P(s) ((s)->flags & MRB_STR_SHARED)
#define RSTR_SET_SHARED_FLAG(s) ((s)->flags |= MRB_STR_SHARED)
#define RSTR_UNSET_SHARED_FLAG(s) ((s)->flags &= ~MRB_STR_SHARED)

#define RSTR_NOFREE_P(s) ((s)->flags & MRB_STR_NOFREE)
#define RSTR_SET_NOFREE_FLAG(s) ((s)->flags |= MRB_STR_NOFREE)
#define RSTR_UNSET_NOFREE_FLAG(s) ((s)->flags &= ~MRB_STR_NOFREE)

#define mrb_str_ptr(s)       ((struct RString*)(mrb_ptr(s)))
#define RSTRING(s)           mrb_str_ptr(s)
#define RSTRING_PTR(s)       RSTR_PTR(RSTRING(s))
#define RSTRING_EMBED_LEN(s) RSTR_ENBED_LEN(RSTRING(s))
#define RSTRING_LEN(s)       RSTR_LEN(RSTRING(s))  
#define RSTRING_CAPA(s)      RSTR_CAPA(RSTRING(s))
#define RSTRING_END(s)       (RSTRING_PTR(s) + RSTRING_LEN(s))
mrb_int mrb_str_strlen(mrb_state*, struct RString*);

#define MRB_STR_SHARED    1
#define MRB_STR_NOFREE    2
#define MRB_STR_EMBED     4
#define MRB_STR_EMBED_LEN_MASK 0xf8
#define MRB_STR_EMBED_LEN_SHIFT 3

void mrb_gc_free_str(mrb_state*, struct RString*);
MRB_API void mrb_str_modify(mrb_state*, struct RString*);
MRB_API void mrb_str_concat(mrb_state*, mrb_value, mrb_value);
MRB_API mrb_value mrb_str_plus(mrb_state*, mrb_value, mrb_value);
MRB_API mrb_value mrb_ptr_to_str(mrb_state *, void*);
MRB_API mrb_value mrb_obj_as_string(mrb_state *mrb, mrb_value obj);
MRB_API mrb_value mrb_str_resize(mrb_state *mrb, mrb_value str, mrb_int len);
MRB_API mrb_value mrb_str_substr(mrb_state *mrb, mrb_value str, mrb_int beg, mrb_int len);
MRB_API mrb_value mrb_string_type(mrb_state *mrb, mrb_value str);
MRB_API mrb_value mrb_check_string_type(mrb_state *mrb, mrb_value str);
MRB_API mrb_value mrb_str_buf_new(mrb_state *mrb, size_t capa);

MRB_API const char *mrb_string_value_cstr(mrb_state *mrb, mrb_value *ptr);
MRB_API const char *mrb_string_value_ptr(mrb_state *mrb, mrb_value ptr);
MRB_API mrb_value mrb_str_dup(mrb_state *mrb, mrb_value str);
MRB_API mrb_value mrb_str_intern(mrb_state *mrb, mrb_value self);
MRB_API mrb_value mrb_str_to_inum(mrb_state *mrb, mrb_value str, mrb_int base, mrb_bool badcheck);
MRB_API double mrb_str_to_dbl(mrb_state *mrb, mrb_value str, mrb_bool badcheck);
MRB_API mrb_value mrb_str_to_str(mrb_state *mrb, mrb_value str);
MRB_API mrb_bool mrb_str_equal(mrb_state *mrb, mrb_value str1, mrb_value str2);
MRB_API mrb_value mrb_str_cat(mrb_state *mrb, mrb_value str, const char *ptr, size_t len);
MRB_API mrb_value mrb_str_cat_cstr(mrb_state *mrb, mrb_value str, const char *ptr);
MRB_API mrb_value mrb_str_cat_str(mrb_state *mrb, mrb_value str, mrb_value str2);
#define mrb_str_cat_lit(mrb, str, lit) mrb_str_cat(mrb, str, lit, mrb_strlen_lit(lit))
MRB_API mrb_value mrb_str_append(mrb_state *mrb, mrb_value str, mrb_value str2);

MRB_API int mrb_str_cmp(mrb_state *mrb, mrb_value str1, mrb_value str2);
MRB_API char *mrb_str_to_cstr(mrb_state *mrb, mrb_value str);
mrb_value mrb_str_pool(mrb_state *mrb, mrb_value str);
mrb_int mrb_str_hash(mrb_state *mrb, mrb_value str);
mrb_value mrb_str_dump(mrb_state *mrb, mrb_value str);
mrb_value mrb_str_inspect(mrb_state *mrb, mrb_value str);

void mrb_noregexp(mrb_state *mrb, mrb_value self);
void mrb_regexp_check(mrb_state *mrb, mrb_value obj);

/* For backward compatibility */
#define mrb_str_cat2(mrb, str, ptr) mrb_str_cat_cstr(mrb, str, ptr)
#define mrb_str_buf_cat(mrb, str, ptr, len) mrb_str_cat(mrb, str, ptr, len)
#define mrb_str_buf_append(mrb, str, str2) mrb_str_cat_str(mrb, str, str2)

#if defined(__cplusplus)
}  /* extern "C" { */
#endif

#endif  /* MRUBY_STRING_H */

