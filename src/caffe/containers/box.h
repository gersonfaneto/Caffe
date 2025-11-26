#ifndef CAFFE_BOX_H_
#define CAFFE_BOX_H_

#ifdef CAFFE_UNPACKED

#include "ensure.h"
#include "macros.h"
#include "types.h"

#else

#include <caffe/core/ensure.h>
#include <caffe/core/macros.h>
#include <caffe/core/types.h>

#endif // ifdef CAFFE_UNPACKED

typedef struct box_t box_t;

struct box_t
{
  box_t* __next;
  var    __data;
  usize  __size;
};

box_t* box_init(var data, usize size);

void box_deinit(box_t* box);

#ifdef CAFFE_FULL_IMPL

#define CAFFE_BOX_IMPL

#endif // ifdef CAFFE_FULL_IMPL

#ifdef CAFFE_BOX_IMPL

#include <stdlib.h>
#include <string.h>

box_t* box_init(var data, usize size)
{
  box_t* box = (box_t*) malloc(sizeof(box_t));

  __ENSURE__(box != NULL, "[ERROR]: Allocation failed!");

  box->__size = size;

  box->__data = malloc(size);

  __ENSURE__(box->__data != NULL, "[ERROR]: Allocation failed!");

  memcpy(box->__data, data, size);

  return box;
}

void box_deinit(box_t* box)
{
  __ENSURE__(box != NULL, "[ERROR]: Invalid reference to object!");
  __ENSURE__(box->__data != NULL, "[ERROR]: Invalid reference to object!");
  free(box->__data);
  free(box);
}

#endif // ifdef CAFFE_BOX_IMPL

#endif // ifndef CAFFE_BOX_H_

// vim:sw=2:ts=2:et:
