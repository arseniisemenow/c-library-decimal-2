# Variables added
CC = gcc
FLAGS = -std=c11 -Wall -Wextra -Werror
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
LINUX_FLAGS = -lcheck -lpthread -lrt -lm -lsubunit
TARGET = s21_decimal.a
TARGET_TEST = ./tests/test_convertors/*.c
DIRECTORIES := func_common func_arithmetic func_comparison func_conversion func_rounding # for_develop
SRC = $(foreach dir, $(DIRECTORIES), $(wildcard $(dir)/*.c)) # All file with .c
OBJ = $(patsubst %.c,$(OBJ_OUTPUT_DIR)/%.o,$(notdir $(SRC))) # All file with .o

OBJ_OUTPUT_DIR=obj_result
TEST_OUTPUT_DIR=tests
GCOV_OUTPUT_DIR=gcov_result

TEST_CHECKS = $(wildcard ./tests/test_*.check) # All file with .check
TEST_CHECK := ./$(TEST_OUTPUT_DIR)/test_united.check # United .check file
TEST_SRC := ./$(TEST_OUTPUT_DIR)/test_united.c # United .c file

MSG=fix: some fix # Commit message
BRANCH=$(shell git branch --show-current) # Current branch

OS := $(shell uname -s) # Current os name
OS := $(patsubst %?,%,$(OS))

ifeq ($(OS),Linux)
	OPEN_CMD = xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
endif

all :
	@make $(TARGET)
	@make test
	@make gcov_report
	
clean :
	@make clean_obj
	@make clean_test
	@make clean_gcov
	@rm -rf *.a *.dSYM ./tests/test_*.c
	@echo "All clean\n"
	@rm -rf *.out

rebuild :
	@make clean
	@make build

style :
	@cp ../materials/linters/.clang-format .clang-format
	@clang-format -i func_common/*.c
	@clang-format -i func_arithmetic/*.c
	@clang-format -i func_comparison/*.c
	@clang-format -i func_conversion/*.c
	@clang-format -i func_rounding/*.c
	@clang-format -i for_develop/*.c
	@clang-format -i headers/*.h
	@rm -rf .clang-format

cppck :
	@#Dont use in this project
	@cppcheck --enable=all --suppress=missingIncludeSystem */*.c

gitgo :
	@make clean
	@git add .
	@git commit -m "$(MSG)"
	@git push origin $(BRANCH)

c:
	@rm -rf dec.out; make clean; make s21_decimal.a; gcc $(FLAGS) tests/func_for_test.c tests/main_test.c s21_decimal.a -o dec.out; ./dec.out

cs:
	@dotnet run --project /Users/peggykri/Documents/C5_s21_decimal-4/src/for_develop/scripts_csc_for_test/script_1/script_1.csproj

comp:	
	@sh for_develop/test_script.sh

v:
	@make c
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  --verbose --log-file=valgrind-out.txt ./dec.out

v_test:
	@make test
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind-out.txt ./tests/unit_test

create_obj_dir : 
	@mkdir -p $(OBJ_OUTPUT_DIR)

$(OBJ) : $(SRC) | create_obj_dir
	@$(foreach src_file,$(SRC), \
			$(CC) $(FLAGS) -c $(src_file) -o $(OBJ_OUTPUT_DIR)/$(notdir $(src_file:.c=.o)); \
	)

build: $(TARGET)

$(TARGET) : $(OBJ)
	@ar rc $@ $(OBJ)
	@ranlib $@

clean_obj :
	@rm -rf $(OBJ_OUTPUT_DIR) *.o


# Create .check -> .c file
# Combines all *.check files into one (TEST_CHECKS -> TEST_CHECK)
$(TEST_SRC) : $(TEST_CHECKS) 
	@echo "#include <stdio.h>" > $(TEST_CHECK)
	@echo "#include \"../s21_decimal.h\"\n" >> $(TEST_CHECK)
	@cat $(TEST_CHECKS) >> $(TEST_CHECK)
	@checkmk clean_mode=1 $(TEST_CHECK) > $(TEST_SRC)
	@clang-format -i $(TEST_SRC)

test : $(TARGET) $(TEST_SRC)
ifeq ($(OS), Darwin)
	@$(CC) $(CFLAGS) $(TEST_SRC) $(TARGET) -o $(TEST_OUTPUT_DIR)/unit_test -lcheck -lm
else
	@$(CC) $(CFLAGS) $(TEST_SRC) $(TARGET) -o $(TEST_OUTPUT_DIR)/unit_test -lcheck  -lm $(LINUX_FLAGS)
endif
	@$(TEST_OUTPUT_DIR)/unit_test

clean_test :
	@rm -rf $(TEST_CHECK) $(TEST_SRC)
	@rm -rf $(TEST_OUTPUT_DIR)/unit_test





gcov_report : $(TEST_SRC) $(SRC)
	@mkdir -p $(GCOV_OUTPUT_DIR)/gcno_result $(GCOV_OUTPUT_DIR)/gcda_result
ifeq ($(OS), Darwin)
	@$(CC) $(CFLAGS) $(GCOV_FLAGS) $(TEST_SRC) $(SRC) -o $(GCOV_OUTPUT_DIR)/gcov_test -lcheck -lm
else
	@$(CC) $(CFLAGS) $(GCOV_FLAGS) $(TEST_SRC) $(SRC) -o $(GCOV_OUTPUT_DIR)/gcov_test -lcheck -lm $(LINUX_FLAGS)
endif
	@cd $(GCOV_OUTPUT_DIR) && ./gcov_test
	@lcov -t "stest" -o $(GCOV_OUTPUT_DIR)/s21_test.info --no-external -c -d . > /dev/null
	@genhtml -o $(GCOV_OUTPUT_DIR)/report $(GCOV_OUTPUT_DIR)/s21_test.info  > /dev/null
	@$(OPEN_CMD) $(GCOV_OUTPUT_DIR)/report/index.html
	@mv *.gcno $(GCOV_OUTPUT_DIR)/gcno_result
	@mv *.gcda $(GCOV_OUTPUT_DIR)/gcda_result

clean_gcov :
	@rm -rf gcov_result *.gcno *.gcda gcov_test s21_test.info

test_c: clean s21_decimal.a
	@$(CC) $(FLAG) -o test $(TARGET_TEST) s21_decimal.a $(LINUX_FLAGS)
	./test