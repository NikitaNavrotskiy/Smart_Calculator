NAME = calc
SRC = view/calc.c controller/calc/callback.c data_structs/node.c controller/calc/draw.c \
	data_structs/stack.c data_structs/list.c modules/alg.c view/main.c data_structs/calc_context.c \
	view/credit.c view/deposit.c controller/credit/callback.c controller/deposit/callback.c \
	modules/annuity.c modules/diff.c controller/value_handler.c controller/validator.c modules/deposit.c \
	controller/credit/calculate.c controller/credit/credit_validator.c controller/deposit/deposit_validator.c \
	controller/deposit/calculate.c controller/credit/value_handler.c  controller/deposit/value_handler.c \
	controller/deposit/deposit_error_handler.c controller/credit/credit_error_handler.c

SRC_TEST = modules/alg.c data_structs/node.c data_structs/stack.c \
	data_structs/list.c test/calc_test.c test/annuity_test.c \test/list_test.c \
	test/stack_test.c test/test.c controller/credit/calculate.c modules/annuity.c \
	modules/diff.c controller/credit/credit_validator.c controller/validator.c \
	test/diff_test.c controller/deposit/calculate.c test/deposit_test.c \
	modules/deposit.c controller/deposit/deposit_validator.c

CC = gcc
TAR_NAME = calc.tar
NAME_TEST = calc_test
FLAGS = --std=c11 -Wall -Werror -Wextra -lm -no-pie -I./
FLAGS_TEST = -lcheck 
DOC_FILE = README.md
STYLE_DIR = style/

all: clean $(NAME)

calc:
	$(CC) `pkg-config --cflags gtk+-3.0` $(SRC) $(FLAGS) -o $(NAME) \
	`pkg-config --libs gtk+-3.0` -export-dynamic -rdynamic

test: clean
	$(CC) $(SRC_TEST) -o $(NAME_TEST) $(FLAGS_TEST) $(FLAGS)
	./$(NAME_TEST)

uninstall: 
	rm -rf ../build/

install: uninstall
	make clean
	make calc
	mkdir ../build
	mv calc ../build
	cp -r style/ ../build

dvi:
	open $(DOC_FILE)

dist: clean all
	tar -cf $(TAR_NAME) $(NAME) $(STYLE_DIR)

clean:
	rm -f $(NAME)
	rm -f $(NAME_TEST)
	rm -f $(NAME_TEST)* $(NAME_TEST)_gcov.info
	rm -rf report
	rm -f $(TAR_NAME)





