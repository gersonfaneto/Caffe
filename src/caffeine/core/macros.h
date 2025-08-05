#ifndef CAFFEINE_MACROS_H_
#define CAFFEINE_MACROS_H_

#include <stdio.h>
#include <stdlib.h>

#define __UNUSED__(X) ((void) (X))

#define __ASSERT__(condition, fmt, ...)          \
  do                                             \
  {                                              \
    if (!(condition))                            \
    {                                            \
      fprintf(stderr, fmt "\n", ##__VA_ARGS__);  \
      exit(1);                                   \
    }                                            \
  }                                              \
  while (0);                                     \

#define __TODO__() \
  __ASSERT__(0, "%s:%d: [TODO]: Something is missing...", __FILE__, __LINE__)

#define __UNREACHABLE__() \
  __ASSERT__(0, "%s:%d: [PANIC]: How did we get here...?", __FILE__, __LINE__)

#endif // ifndef CAFFEINE_MACROS_H_

// vim:sw=2:ts=2:et:
