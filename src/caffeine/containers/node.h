#ifndef CAFFEINE_NODE_H_
#define CAFFEINE_NODE_H_

#include <caffeine/core/types.h>

typedef struct node_t node_t;

struct node_t
{
  node_t* __next;
  var     __data;
  usize   __size;
};

node_t* node_init(var data, usize size);

void node_deinit(node_t* node);

#ifdef CAFFEINE_NODE_IMPLEMENTATION

node_t* node_init(var data, usize size)
{
  __UNUSED__(data);
  __UNUSED__(size);
  __TODO__();
}

void node_deinit(node_t* node)
{
  __UNUSED__(node);
  __TODO__();
}

#endif // ifdef CAFFEINE_NODE_IMPLEMENTATION

#endif // ifndef CAFFEINE_NODE_H_
