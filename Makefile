# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 16:07:28 by rjaakonm          #+#    #+#              #
#    Updated: 2020/01/16 13:41:53 by rjaakonm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS =	srcs/main.c \
		srcs/burning_ship.c \
		srcs/controls.c \
		srcs/help_funcs.c \
		srcs/help_funcs2.c \
		srcs/julia.c \
		srcs/mandelbrot.c \
		srcs/mouse.c \
		srcs/own.c

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

LIB = -L libft -lft -lmlx -framework OpenGL -framework AppKit
# -L ./minilibx/

INCL = -I incl/ -I libft/libft/incl/ -I libft/printf/incl/

.PHONY: all clean fclean re run run2

all: $(NAME)

$(NAME): libftmake
	gcc $(FLAGS) $(INCL) $(SRCS) $(LIB) -o $(NAME)

libftmake:
	@make -C libft

clean:
#	@rm -f $(notdir $(OBJS))
#	@rm -f $(OBJS)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

run:
	gcc $(FLAGS) $(INCL) $(SRCS) $(LIB) -o $(NAME)
	./fractol 1

run2:
	gcc $(FLAGS) $(INCL) $(SRCS) $(LIB) -o $(NAME)
	./fractol 2

run3:
	gcc $(FLAGS) $(INCL) $(SRCS) $(LIB) -o $(NAME)
	./fractol 3

run4:
	gcc $(FLAGS) $(INCL) $(SRCS) $(LIB) -o $(NAME)
	./fractol 4
