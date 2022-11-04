# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 18:32:58 by abeihaqi          #+#    #+#              #
#    Updated: 2022/11/04 17:28:33 by abeihaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c create_arg.c parse_arg.c print_arg.c print_char.c\
	   print_str.c print_add.c print_num.c print_ux.c ft_atoi.c ft_strchr.c\
	   ft_isdigit.c ft_strlen.c ft_itoa.c ft_itoa_base.c ft_calloc.c\
	   ft_memset.c ft_utoa_base.c ft_strdup.c print_seq.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(NAME)

debug: $(NAME)
	clear
	$(CC) $(CFLAGS) main.c $(NAME) -fsanitize=address -g
	./a.out

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f  $(NAME) a.out

re: fclean all

.PHONY: all clean fclean re debug
