##
## EPITECH PROJECT, 2024
## B-CCP-400-COT-4-1-panoramix-christiany.akotenou
## File description:
## Makefile
##


CC      = gcc
CFLAGS  = -Wall -Wextra -g -pthread

SRC     =   panoramix.c  \
            main.c       \
            init.c       \
            create_cln.c \

OBJ     = $(SRC:.c=.o)

BIN     = panoramix

all: $(BIN)

$(BIN): $(OBJ)
    $(CC) $(CFLAGS) -o $(BIN) $(OBJ)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -rf *.o
    rm -rf *.gcno *.gcda
    rm -f unit_tests

fclean: clean
	rm -f $(BIN)

re: fclean all

tests_run:
    @$(CC) $(CFLAGS) -I. -o unit_tests $(OBJ) tests/*.c -lcriterion --coverage # MODIFIÉ : Ajout de -I., $(OBJ), et tests/*.c
    @./unit_tests