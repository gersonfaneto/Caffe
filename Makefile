CC     ?= cc

CFLAGS := -Wall -Wextra -Wpedantic -Werror
CFLAGS += \
	  # -Wno-redefined-macro

CFLAGS += -std=c99 -pedantic
CFLAGS += -Os
CFLAGS += -g -ggdb

CFLAGS += -I src/

# UFLAGS ?= -DNDEBUG

.PHONY: help
help:
	@echo "Usage: make [compdb|build|run|clean]"

.PHONY: build
build:
	@[[ ! -d ./dist/ ]] && mkdir ./dist/ || exit 0
	cc -o ./dist/10-box examples/10-box.c $(CFLAGS) $(UFLAGS)
	cc -o ./dist/11-list examples/11-list.c $(CFLAGS) $(UFLAGS)

.PHONY: run
run:
	@[[ -d ./dist/ ]] && (exit 0) || (echo "Do 'make build' first!"; exit 1)
	@./dist/10-box
	@./dist/11-list

.PHONY: compdb
compdb:
	@[[ ! -d ./.build/ ]] && mkdir ./.build/ || exit 0
	bear --output ./.build/compile_commands.json -- make build

.PHONY: format
format:
	find -type f -name '*.[c|h]' | xargs -I {} clang-format -i --verbose {}

.PHONY: clean
clean:
	@rm -f -r ./.build ./dist
