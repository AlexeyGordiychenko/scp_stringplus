CC := gcc
CFLAGS := -Wall -Wextra -Werror -std=c11
LDFLAGS := -lcheck -pthread -lgcov -lm -lrt
ifeq ($(shell uname), Linux)
	LDFLAGS += -lsubunit
endif
GCOVFLAGS=--coverage

SRC_DIR := src
OBJ_DIR := obj
GCOV_DIR := gcov
GCOV_OBJ_DIR := obj/$(GCOV_DIR)
TEST_DIR := tests

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
OBJS_GCOV=$(patsubst $(SRC_DIR)/%.c,$(GCOV_OBJ_DIR)/%.o,$(SRCS))

TEST_SRCS := $(wildcard $(TEST_DIR)/*.c)
LIB := scp_string.a
TEST := test

.PHONY: all $(TEST) $(LIB) gcov_report clean rebuild clang_n clang_i valgrind

all: $(LIB)

$(TEST): $(OBJS_GCOV) $(TEST_SRCS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@
	./$@

$(LIB): $(OBJS)
	ar rcs $(LIB) $^
	
gcov_report:
	mkdir -p $(GCOV_DIR)
	gcovr --html-details -o $(GCOV_DIR)/index.html --filter "$(SRC_DIR)/*"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(GCOV_OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(GCOV_OBJ_DIR)
	$(CC) $(CFLAGS) $(GCOVFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(GCOV_DIR) $(TEST) $(LIB)

rebuild: clean all

clang_n:
	clang-format -n --style=Google $(SRC_DIR)/*.[ch] $(TEST_DIR)/*.[ch]

clang_i:
	clang-format -i --style=Google $(SRC_DIR)/*.[ch] $(TEST_DIR)/*.[ch]

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./$(TEST)
