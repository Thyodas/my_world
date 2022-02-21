##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC = src/main.c

OBJ = $(SRC:.c=.o)

NAME = my_world

INCLUDE = include

LIB = lib/my

CFLAGS = -I$(INCLUDE) -Wall -Wextra -g

%.o: %.c
	@echo "👉️ Compiling \033[1m$<\033[0m"
	@$(CC) $(CFLAGS) -c -o $@ $<

all:
	@$(MAKE) -s $(NAME)

make_lib:
		  make -C $(LIB)

title:
		@echo "\033[1;37m\033[1;46m                   MY_WORLD\
                    \033[0m"

$(NAME): make_lib title $(OBJ)
		 gcc -g -o $(NAME) $(OBJ) -L$(LIB) -lmy -lcsfml-graphics \
		 -lcsfml-system -lm
		 rm -f $(OBJ)

clean:
	   make clean -C $(LIB)
	   rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: fclean title all debug re clean tests_run make_lib $(NAME)
