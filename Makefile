CFLAGS=-Wall -Wextra -Wpedantic -Werror -std=gnu99

all:
	cc -o .build/10-list examples/10-list.c -I src/ $(CFLAGS) && .build/10-list
