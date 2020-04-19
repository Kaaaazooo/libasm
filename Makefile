NAME = libfts.a

CC = gcc
FLAGS = -Wall -Werror -Wextra

SRCS = $(addprefix srcs/, ft_strlen.s ft_strcpy.s ft_strcmp.s \
	ft_write.s ft_read.s)

%.o : %.s
	nasm -f elf64 $< -o $@

OBJS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

main: all
	$(CC) main.c libfts.a
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf a.out

re: fclean all
