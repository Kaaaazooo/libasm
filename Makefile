# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 13:52:43 by sabrugie          #+#    #+#              #
#    Updated: 2020/10/27 13:57:34 by sabrugie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

CC = gcc
FLAGS = -Wall -Werror -Wextra

SRCS = $(addprefix srcs/, ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s \
	   	ft_write.s ft_read.s)

%.o : %.s
	nasm -f macho64 $< -o $@

OBJS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

main: all
	$(CC) main.c $(NAME)
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf a.out

re: fclean all
