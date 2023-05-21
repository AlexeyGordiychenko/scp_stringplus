CC := gcc
CFLAGS := -Wall -Wextra -Werror -std=c11 --coverage
LDFLAGS := -lcheck -pthread -lm
ifeq ($(shell uname), Linux)
	LDFLAGS += -lsubunit -lgcov
endif
SRC_DIR := src
OBJ_DIR := obj
GCOV_DIR := gcov
TEST_DIR := tests

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
TEST_SRCS := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS := $(patsubst $(TEST_DIR)/%.c,$(OBJ_DIR)/%.o,$(TEST_SRCS))
LIB := s21_string.a
EXECUTABLE := test

.PHONY: all test s21_string.a gcov_report clean rebuild clang_n clang_i valgrind

all: s21_string.a

test: $(TEST_OBJS) $(LIB)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(LIB) $(LDFLAGS) -o $(EXECUTABLE)
	./test

s21_string.a: $(OBJS)
	ar rcs $(LIB) $(OBJS)

gcov_report:
	mkdir -p $(GCOV_DIR)
	gcovr --html-details -o $(GCOV_DIR)/index.html --filter "src/*"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TEST_OBJS) $(GCOV_DIR) $(EXECUTABLE) $(LIB)

rebuild: clean all

clang_n:
	clang-format -n --style=Google src/*.[ch] tests/*.[ch]

clang_i:
	clang-format -i --style=Google src/*.[ch] tests/*.[ch]

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./test
