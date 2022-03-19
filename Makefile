##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC = src/main.c \
	  src/display/draw_map.c \
	  src/display/draw_interface.c \
	  src/display/main_loop.c \
	  src/game/events/check_events.c \
	  src/game/events/check_interface.c \
	  src/game/events/tools/on_click_func.c \
	  src/map/create_2d_map.c \
	  src/map/utils_map/init_map.c \
	  src/window/init_window.c \
	  src/textures/load_textures.c \
	  src/game/events/rotate.c \
	  src/utils/math/calc_dist.c \
	  src/utils/check_pos_in_tile.c \
	  src/interface/buttons.c \
	  src/interface/tools/button_actions.c \
	  src/interface/tools/utils.c \
	  src/interface/backgrounds.c \
	  src/interface/tooltips.c \
	  src/utils/math/atof.c \
	  src/game/save_map/save.c

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
		 -lcsfml-system -lcsfml-window -lm
		 rm -f $(OBJ)

clean:
	   make clean -C $(LIB)
	   rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: fclean title all debug re clean tests_run make_lib $(NAME)
