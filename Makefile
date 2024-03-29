# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/28 14:42:19 by rtoast            #+#    #+#              #
#    Updated: 2021/02/08 21:25:39 by kshanti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

C_FILE = ft_parser.c ft_printf.c ft_proces.c ft_processor.c libfile.c\
		 libfiletwo.c ft_processor_2.0.c\
		 main.c###############

O_FILE = $(C_FILE:.c=.o)

HEAD =	ft_printf.h

FLAGS = #-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(O_FILE)
	ar -rcs $(NAME) $(O_FILE)

%.o: %.c $(HEAD)
	gcc -c $(FLAGS) $< -o $@

clean:
	@rm -f $(O_FILE)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re