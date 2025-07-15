UNAME_S := $(shell uname -s)
CC := gcc

SRC_DIR := .
TEST_DIR := ./test

CHECK_H_PATH := /opt/homebrew/include/check.h
CHECK_INCLUDE :=
ifeq ($(wildcard $(CHECK_H_PATH)), $(CHECK_H_PATH))
    CHECK_INCLUDE := -I/opt/homebrew/include
endif

ifeq ($(UNAME_S),Darwin)
    CFLAGS := -Wall -Wextra -Werror -Wno-error=format -std=c11 -g $(CHECK_INCLUDE) -I$(SRC_DIR) -I$(TEST_DIR)
    LDFLAGS := -L/opt/homebrew/lib -lcheck -lm
else
    CFLAGS := -Wall -Wextra -Werror -Wno-error=format -std=c11 -g -I$(SRC_DIR) -I$(TEST_DIR)
    LDFLAGS := -lcheck -lm -lsubunit
endif

COVERAGE_FLAGS := -fprofile-arcs -ftest-coverage -g

TARGET := $(SRC_DIR)/s21_string.a
TEST_BIN := $(SRC_DIR)/test_all

SRCS := $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)/*.c))
TEST_SRCS := $(wildcard $(TEST_DIR)/*.c)

OBJS := $(SRCS:.c=.o)
TEST_OBJS := $(TEST_SRCS:.c=.o)

COV_OBJS := $(SRCS:.c=.cov.o)
COV_TEST_OBJS := $(TEST_SRCS:.c=.cov.o)

FORMAT_SRCS := $(SRCS) $(SRC_DIR)/s21_string.h $(TEST_SRCS)

.PHONY: all clean fclean re test gcov_report format check_tools

all: $(TARGET)

$(TARGET): $(OBJS)
	@ar rcs $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/%.cov.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(COVERAGE_FLAGS) -c $< -o $@

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(TEST_DIR)/%.cov.o: $(TEST_DIR)/%.c
	@$(CC) $(CFLAGS) $(COVERAGE_FLAGS) -c $< -o $@

test: $(COV_OBJS) $(COV_TEST_OBJS)
	$(CC) $(COV_OBJS) $(COV_TEST_OBJS) $(CFLAGS) $(LDFLAGS) $(COVERAGE_FLAGS) -o $(TEST_BIN)
	@./$(TEST_BIN)

valgrind: test
	@command -v valgrind >/dev/null 2>&1 && \
	valgrind --leak-check=full --show-leak-kinds=all ./$(TEST_BIN) || \
	echo "⚠️  valgrind не установлен"

gcov_report: test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage-report
	@echo "📄 HTML-отчёт создан: открой ./coverage-report/index.html в браузере."

format:
	@command -v clang-format >/dev/null 2>&1 && \
	clang-format -i $(FORMAT_SRCS) || \
	echo "⚠️  clang-format не установлен"

check_tools:
	@command -v clang-format >/dev/null 2>&1 || echo "⚠️  Установи: clang-format"
	@command -v valgrind >/dev/null 2>&1 || echo "⚠️  Установи: valgrind"
	@command -v lcov >/dev/null 2>&1 || echo "⚠️  Установи: lcov"

clean:
	rm -f $(OBJS) $(TEST_OBJS) $(COV_OBJS) $(COV_TEST_OBJS) $(TEST_BIN)
	find . \( -name "*.gcda" -o -name "*.gcno" -o -name "*.gcov" \) -delete
	rm -f coverage.info
	rm -rf coverage-report

fclean: clean
	rm -f $(TARGET)

re: fclean all
