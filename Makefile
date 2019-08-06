#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 16:39:46 by tbahlai           #+#    #+#              #
#    Updated: 2019/02/13 16:39:47 by tbahlai          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME    = wolf3d

SRC     = src/main.c \
			src/draw_text_floor.c \
			src/draw_texture.c \
			src/error.c \
			src/initial_texture.c \
			src/keys.c \
			src/move.c \
			src/raycasting.c \
			src/menu.c \
			src/valid_file.c

OBJ     = $(SRC:.c=.o)
LIBFT   = lib/
HDR  = includes/wolf.h 
CC      = /usr/bin/gcc
CFLAGS  = -Wall -Wextra -Werror
FMLX    = -framework OpenGL -framework AppKit -lmlx
DEL      = /bin/rm -f

all:        $(NAME)

$(NAME):    $(OBJ) $(LIBFT)
	@make -C $(LIBFT)	
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I $(HDR) -L $(LIBFT)  -lft $(FMLX)
	@echo "\x1b[32m -->> Compilation Success: wolf3d"

%.o : %.c $(HDR) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ -c $< -I .

clean:
	@make fclean -C $(LIBFT)
	@$(DEL) $(OBJ)
	@echo "\x1b[32m -->> Object files are deleted"

fclean:     clean
	@make -C $(LIBFT) fclean
	@$(DEL) $(NAME)
	@echo "\x1b[32m -->> wolf3d was deleted"


re:     fclean all

.PHONY:     re all clean fclean