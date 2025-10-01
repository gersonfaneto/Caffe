CFLAGS  = -Wall -Wextra -Wpedantic -Werror -std=gnu99
CFLAGS += -D__DEBUG__
CFLAGS += -g -ggdb

all:
	@[[ ! -d .build/ ]] && mkdir .build || exit 0
	@cc -o .build/10-box examples/10-box.c -I src/ $(CFLAGS) && .build/10-box 1> /dev/null
	@cc -o .build/11-list examples/11-list.c -I src/ $(CFLAGS) && .build/11-list 1> /dev/null


compilation-db:
	@[[ ! -d .build/ ]] && mkdir .build || exit 0
	@bear --output .build/compile_commands.json -- $(MAKE)


format:
	@find -type f -name '*.[c|h]' -exec clang-format --verbose -i {} \;


clean:
	@rm -r -v .build/
