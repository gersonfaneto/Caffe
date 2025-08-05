#define CAFFEINE_LIST_IMPLEMENTATION

#include <caffeine/core/types.h>
#include <caffeine/containers/list.h>

#include <stdio.h>

int main(void)
{
  list_t list = list_init();

  for (int i = 0; i < 10; ++i)
  {
    int x = (i + 1);
    list.insert(&list, &x, sizeof(x), i);
  }

  usize count = list.__lenght;
  printf("list.__lenght :: %lu\n", count);

  for (usize i = 0; i < (count / 2); ++i)
  {
    usize j = (count - i - 1);
    var x = NULL;
    list.retrieve(&list, j, &x);
    list.remove(&list, j);
    printf("@%lu :: %d\n", j, *(int*) x);
    free(x);
  }

  count = list.__lenght;
  printf("list.__lenght :: %lu\n", count);

  list.clear(&list);

  count = list.__lenght;
  printf("list.__lenght :: %lu\n", count);

  return 0;
}

// vim:sw=2:ts=2:et:
