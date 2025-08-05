#ifndef CAFFEINE_LIST_H_
#define CAFFEINE_LIST_H_

#include <caffeine/core/types.h>
#include <caffeine/core/macros.h>

#include <stddef.h>

typedef struct node_t node_t;

struct node_t
{
	node_t* __next;
	var     __data;
	usize   __size;
};

typedef struct list_t list_t;

struct list_t
{
	node_t* __leader;
	usize   __lenght;

  void (*clear)(list_t* self);
  void (*insert)(list_t* self, var data, usize size, usize position);
  void (*remove)(list_t* self, usize position);
  void (*retrieve)(list_t* self, usize position, var* store);
};

list_t list_init(void);

#ifdef CAFFEINE_LIST_IMPLEMENTATION

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
	return (list_t)
  {
    .__leader = NULL,
    .__lenght = 0,

    .clear    = list_clear,
    .insert   = list_insert,
    .remove   = list_remove,
    .retrieve = list_retrieve,
  };
}

#endif // ifdef CAFFEINE_LIST_IMPLEMENTATION

#endif // ifndef CAFFEINE_LIST_H_

// vim:sw=2:ts=2:et:
