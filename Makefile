##
## EPITECH PROJECT, 2024
## B-CCP-400-COT-4-1-panoramix-christiany.akotenou
## File description:
## Makefile
##

##
## EPITECH PROJECT, 2024
## makefile
## File description:
## make
##

SRC	=	panoramix.c	\
		main.c	\
		init.c	\
		create_cln.c	\

OBJ	=	$(subst .c,.o,$(SRC))

BIN	=	panoramix

all: $(BIN)

$(BIN):		$(SRC)
		gcc -o $(BIN) $(SRC)
clean:
	rm -rf *.o
fclean: clean
	rm -f $(BIN)
re: fclean all
