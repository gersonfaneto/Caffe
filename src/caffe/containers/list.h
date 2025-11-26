#ifndef CAFFE_LIST_H_
#define CAFFE_LIST_H_

#ifdef CAFFE_UNPACKED

#include "ensure.h"
#include "macros.h"
#include "types.h"

#include "box.h"

#else

#include <caffe/core/ensure.h>
#include <caffe/core/macros.h>
#include <caffe/core/types.h>

#include <caffe/containers/box.h>

#endif // ifdef CAFFE_UNPACKED

typedef struct list_t list_t;

struct list_t
{
  box_t* __leader;
  usize  __lenght;

  void (*clear)(list_t* self);
  void (*insert)(list_t* self, var data, usize size, usize position);
  void (*remove)(list_t* self, usize position);
  void (*retrieve)(list_t* self, usize position, var* store);
};

list_t list_init(void);

#ifdef CAFFE_FULL_IMPL

#define CAFFE_BOX_IMPLe
#define CAFFE_LIST_IMPL

#endif // ifdef CAFFE_FULL_IMPL

#ifdef CAFFE_LIST_IMPL

#include <stddef.h>
#include <stdlib.h>

void list_clear(list_t* self)
{
  __UNUSED__(self);
  __TODO__();
}

void list_insert(list_t* self, var data, usize size, usize position)
{
  __UNUSED__(self);
  __UNUSED__(data);
  __UNUSED__(size);
  __UNUSED__(position);
  __TODO__();
}

void list_remove(list_t* self, usize position)
{
  __UNUSED__(self);
  __UNUSED__(position);
  __TODO__();
}

void list_retrieve(list_t* self, usize position, var* store)
{
  __UNUSED__(self);
  __UNUSED__(store);
  __UNUSED__(position);
  __TODO__();
}

list_t list_init(void)
{
  return (list_t) {
      .__leader = NULL,
      .__lenght = 0,

      .clear    = list_clear,
      .insert   = list_insert,
      .remove   = list_remove,
      .retrieve = list_retrieve,
  };
}

#endif // ifdef CAFFE_LIST_IMPL

#endif // ifndef CAFFE_LIST_H_

// vim:sw=2:ts=2:et:
