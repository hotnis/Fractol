# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/17 07:18:58 by mzane             #+#    #+#              #
#    Updated: 2015/06/08 16:00:04 by mzane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = ark.c mandelbrot.c main.c complexe.c hook.c utils.c julia.c hook_julia.c

OBJS =		$(SRCS:.c=.o)

INCLUDES =	-I libft/ \
		   	-I minilibx_macos/ \
		   	-I includes/

LIBS =		-L libft/ -lft \
			-L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

FLAGS =		-g -Wall -Wextra -Werror


$(NAME):	$(OBJS)
				@make -C libft/ fclean
				@make -C libft/
				@make -C minilibx_macos/ clean
				@make -C minilibx_macos/
				@echo "Create binary" 
				@gcc -o $(NAME) $(OBJS) $(LIBS)
				@echo "Complitation ok"

$(OBJS): %.o: %.c
				@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

all:		$(NAME)

clean:
	rm -f	$(OBJS)

fclean: clean
	rm -f	$(NAME)

re: fclean all

.PHONY:	 all clean fclean re
