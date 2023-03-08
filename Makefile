# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 17:09:26 by jvasseur          #+#    #+#              #
#    Updated: 2023/03/08 16:48:43 by jvasseur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang -g

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

SRC = pipex.c send_error.c

LIBFT = -lXext -lX11 -lm -lz

MAKE = make -C

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(MAKE) Libft
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME) -LLibft -lft -LLibft/ft_printf -lftprintf
	
all : $(NAME)

clean :
	make -C Libft clean
	rm -f $(OBJ)

fclean : clean
	make -C Libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
