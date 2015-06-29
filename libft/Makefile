# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 15:15:06 by mzane             #+#    #+#              #
#    Updated: 2015/06/08 01:42:07 by mzane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_strdup.c ft_strncmp.c ft_strlen.c ft_strcat.c \
		ft_strcmp.c ft_strcpy.c ft_strrchr.c ft_strchr.c \
		ft_strnew.c ft_putnbr_fd.c ft_putnbr.c ft_memccpy.c \
		ft_memcpy.c ft_putstr_fd.c ft_putchar.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putstr.c ft_strnequ.c ft_strequ.c \
		ft_strclr.c ft_tolower.c ft_toupper.c ft_isalnum.c \
		ft_isprint.c ft_isascii.c ft_isalpha.c ft_isdigit.c \
		ft_bzero.c ft_memset.c ft_strncpy.c ft_strncat.c \
		ft_memmove.c ft_memchr.c ft_memcmp.c \
		ft_memalloc.c ft_memdel.c ft_strdel.c ft_strstr.c \
		ft_atoi.c ft_striter.c ft_striteri.c ft_strmap.c \
		ft_strsub.c	ft_strjoin.c ft_strtrim.c ft_itoa.c \
		ft_strlcat.c ft_strsplit.c ft_strnstr.c ft_strmapi.c \
		ft_putendl.c ft_lstnew.c ft_lstmap.c ft_lstadd.c \
		ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_abs.c \
		get_next_line.c wdmatch.c ft_trijoin.c ft_realloc.c \
		ft_lowstr.c

OBJS =	$(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	@echo "Creation de la libft"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "libft ok"

$(OBJS): %.o: %.c
	@gcc -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all
