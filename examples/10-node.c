#define CAFFE_NODE_IMPLEMENTATION

#include <caffe/core/types.h>
#include <caffe/containers/node.h>

#include <stdio.h>

int main(void)
{
  char* msg = "Hello, World!";

  node_t* node = node_init(msg, strlen(msg));

  printf("%s\n", ( char* )node->__data);

  node_deinit(node);

  return 0;
}

// vim:sw=2:ts=2:et:
