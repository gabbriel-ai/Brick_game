.PHONY: all install uninstall clean dvi dist test gcov_report

CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
COV_FLAGS = -fprofile-arcs -ftest-coverage

LIBS=-lncurses
BASE_DIR=$(pwd)

DIRS= gui/cli
BACK_SRC=$(wildcard brick_game/tetris/*.c) 
FRONT_SRC=$(wildcard gui/cli/*.c)
BACK_OBJS = $(BACK_SRC:%.c=%.o)
FRONT_OBJS = $(FRONT_SRC:%.c=%.o)

SYSTEM := $(shell uname -s)

ifeq ($(SYSTEM), Linux)
    SYSTEM_FLAGS =  -lcheck -lpthread -lrt -lsubunit -lm
else ifeq ($(SYSTEM), Darwin)
    SYSTEM_FLAGS = -lcheck
endif


all: install

install: tetris_lib.a front_lib.a
	mkdir -p tetris-1.0
	$(CC) $(CFLAGS) tetris.c -o tetris-1.0/tetris.exe tetris_lib.a front_lib.a -lncurses
	make clean

uninstall:
	rm -rf tetris-1.0
	rm -rf data

tetris_lib.a: $(BACK_OBJS)
	ar rcs $@ $^

front_lib.a: $(FRONT_OBJS)
	ar rcs $@ $^

dist: install
	tar czvf tetris-1.0.tar --ignore-failed-read tetris-1.0
	make uninstall

dvi:
	doxygen

test: tetris_lib.a
	$(CC) $(CFLAGS) tests/unit_test.c -o test.exe tetris_lib.a $(SYSTEM_FLAGS)
	./test.exe

gcov_report:
	gcc $(CFLAGS) $(COV_FLAGS) $(BACK_SRC) tests/unit_test.c -o test.exe $(SYSTEM_FLAGS) 
	./test.exe
	lcov --capture --directory .  --output-file coverage.info
	lcov --remove coverage.info '*/tests/*' --output-file coverage.info
	genhtml coverage.info --output-directory coverage_report
	rm -rf *.gc* test coverage.info decimal_test


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BACK_OBJS) $(FRONT_OBJS)
	rm -rf tetris_lib.a front_lib.a
	rm -rf tetris-1.0.tar
	rm -rf doxygen
	rm -rf test.exe
	rm -rf coverage_report
	rm -rf data