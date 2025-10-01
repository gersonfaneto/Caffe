#ifndef CAFFE_NODE_H_
#define CAFFE_NODE_H_

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

typedef struct node_t node_t;

struct node_t
{
  node_t* __next;
  var     __data;
  usize   __size;
};

node_t* node_init(var data, usize size);

void node_deinit(node_t* node);

#ifdef CAFFE_ALL_IMPLEMENTATIONS

#define CAFFE_NODE_IMPLEMENTATION

#endif // ifdef CAFFE_ALL_IMPLEMENTATIONS

#ifdef CAFFE_NODE_IMPLEMENTATION

node_t* node_init(var data, usize size)
{
  node_t* node = ( node_t* )malloc(sizeof(node_t));

  __ENSURE__(node != NULL, "[ERROR]: Allocation failed!");

  node->__size = size;

  node->__data = malloc(size);

  __ENSURE__(node->__data != NULL, "[ERROR]: Allocation failed!");

  memcpy(node->__data, data, size);

  return node;
}

void node_deinit(node_t* node)
{
  __ENSURE__(node != NULL, "[ERROR]: Invalid reference to object!");
  __ENSURE__(node->__data != NULL, "[ERROR]: Invalid reference to object!");
  free(node->__data);
  free(node);
}

#endif // ifdef CAFFE_NODE_IMPLEMENTATION

#endif // ifndef CAFFE_NODE_H_
