##
## EPITECH PROJECT, 2024
## rush2
## File description:
## Makefile
##

CC := gcc -std=gnu11
CFLAGS := -W -Wall -Wextra -Wunused -Wpedantic
CFLAGS += -Wundef -Wshadow -Wcast-align
CFLAGS += -Wstrict-prototypes -Wmissing-prototypes
CFLAGS += -Waggregate-return -Wcast-qual
CFLAGS += -Wunreachable-code
CFLAGS += -U_FORTIFY_SOURCE
CFLAGS += -iquote ./.
LDFLAGS :=

NAME := unit_tests

VPATH := ../
SRC := array.c
SRC += char.c
SRC += float.c
SRC += int.c
SRC += list.c
SRC += new.c
SRC += player.c
SRC += point.c
SRC += vertex.c

VPATH += ../tests/
SRC += test.c
SRC += test_vertex.c

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): CFLAGS += -g3 --coverage
$(NAME): LDFLAGS += -lcriterion --coverage
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

tests_run: re
	./$(NAME)

.PHONY: $(NAME) tests_run

re: fclean
	$(MAKE)

.PHONY: re

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

.PHONY: clean fclean