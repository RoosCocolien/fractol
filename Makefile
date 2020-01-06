# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rsteigen <rsteigen@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/03 13:56:54 by rsteigen       #+#    #+#                 #
#    Updated: 2020/01/06 13:59:08 by rsteigen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIBFT = libft/
MINILIBX = minilibx_macos/
FLAGS = -Wall -Wextra -Werror
FUNCS = setup.c color.c draw.c events.c free.c close.c settings.c

all: $(NAME)
.PHONY: all

$(NAME):
	@make -C minilibx_macos/ clean && make -C $(MINILIBX)
	echo Succeeded making: $(MINILIBX)
	@make -C libft/ fclean && make -C libft/
	echo Succeeded making: $(LIBFT)
	@gcc $(FLAGS) -I includes/ -I minilibx_macos -c $(FUNCS)
	@gcc $(FLAGS) -I includes/ -I minilibx_macos -c main.c
	@gcc -o $(NAME) main.o $(FUNCS:.c=.o) -I includes -I minilibx_macos -L \
	libft/ -lft -L minilibx_macos -lmlx -framework OpenGL -framework APPkit
	echo Succeeded making: $(NAME)

clean:
	@/bin/rm -f $(FUNCS:.c=.o) main.o *~
	@make -C $(LIBFT) clean
	@make -C $(MINILIBX) clean

fclean: clean
	@/bin/rm -f $(NAME)
	echo Cleaned libft and minilibx_macos

re: fclean all

