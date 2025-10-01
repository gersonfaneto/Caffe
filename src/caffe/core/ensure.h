#ifndef CAFFE_ASSERT_H_
#define CAFFE_ASSERT_H_

#include <stdio.h>
#include <stdlib.h>

#ifdef __DEBUG__

#define __ENSURE__(condition, fmt, ...)                                       \
  do                                                                          \
  {                                                                           \
    if (!(condition))                                                         \
    {                                                                         \
      fprintf(stderr, "%s:%d: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__); \
      exit(1);                                                                \
    }                                                                         \
  } while (0);

#else

#define __ENSURE__(condition, fmt, ...) (( void )0)

#endif // ifdef __DEBUG__

#ifdef CAFFE_ENSURE_EXTRAS

#ifdef __DEBUG__

#define __TODO__() \
  __ENSURE__(0, "%s:%d: [TODO]: Something is missing...", __FILE__, __LINE__)

#define __UNREACHABLE__() \
  __ENSURE__(0, "%s:%d: [PANIC]: How did we get here...?", __FILE__, __LINE__)

#else

#define __TODO__() (( void )0)
#define __UNREACHABLE__() (( void )0)

#endif // ifdef __DEBUG__

#endif // ifdef CAFFE_ENSURE_EXTRAS

#endif // ifndef CAFFE_ASSERT_H_

// vim:sw=2:ts=2:et:
