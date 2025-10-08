#define CAFFE_BOX_IMPLEMENTATION

#include <caffe/core/types.h>
#include <caffe/containers/box.h>

#include <stdio.h>

int main(void)
{
  char* msg = "Hello, World!";

  box_t* box = box_init(msg, strlen(msg));

  printf("%s\n", (char*) box->__data);

  box_deinit(box);

  return 0;
}

// vim:sw=2:ts=2:et:
