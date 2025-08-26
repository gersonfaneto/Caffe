CFLAGS  = -Wall -Wextra -Wpedantic -Werror -std=gnu99
CFLAGS += -D__DEBUG__

all:
	[[ ! -d .build/ ]] && mkdir .build || exit 0
	cc -o .build/10-list examples/10-list.c -I src/ $(CFLAGS) && .build/10-list


format:
	find -type f -name '*.[c|h]' -exec clang-format --verbose -i {} \;


clean:
	rm -r -v .build/
