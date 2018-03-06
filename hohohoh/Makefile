#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abulakh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/24 19:46:54 by abulakh           #+#    #+#              #
#    Updated: 2018/02/24 19:46:55 by abulakh          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =  libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HIDDIRS = -I . ft_printf.h

SRC = ft_printf_start.c

RM = rm -f

OBJ = $(patsubst %.c,./%.o,$(SRC))

LIB = ./gnltry2/libft/*.c

OBJLB = ./*.o

MAKE = make

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -I . -I./gnltry2/libft -Wall -Wextra -Werror -c $(SRCS) $(LIB)
	@ar rc $(NAME) $(OBJ) $(OBJLB)
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJ) $(OBJLB)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re