#ifndef CAFFE_BOX_H_
#define CAFFE_BOX_H_

#include <string.h>

#ifndef CAFFE_UNPACKED

#include <caffe/core/ensure.h>
#include <caffe/core/macros.h>
#include <caffe/core/types.h>

#else

#include "ensure.h"
#include "macros.h"
#include "types.h"

#endif // ifndef CAFFE_UNPACKED

typedef struct box_t box_t;

struct box_t
{
  box_t* __next;
  var    __data;
  usize  __size;
};

box_t* box_init(var data, usize size);

void box_deinit(box_t* box);

#ifdef CAFFE_ALL_IMPLEMENTATIONS

#define CAFFE_BOX_IMPLEMENTATION

#endif // ifdef CAFFE_ALL_IMPLEMENTATIONS

#ifdef CAFFE_BOX_IMPLEMENTATION

box_t* box_init(var data, usize size)
{
  box_t* box = ( box_t* )malloc(sizeof(box_t));

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

#endif // ifdef CAFFE_BOX_IMPLEMENTATION

#endif // ifndef CAFFE_BOX_H_
