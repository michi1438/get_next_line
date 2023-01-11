# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 12:41:15 by mguerga           #+#    #+#              #
#    Updated: 2023/01/11 19:54:18 by xbeheydt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

CC = gcc

CFLAGS = -Werror -Wall -Wextra -g -fsanitize=address

SRC = get_next_line.c get_next_line_utils.c

SRCB = get_next_line_utils_bonus.c get_next_line_bonus.c

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

test: re 
	$(CC) $(CFLAGS) $(OBJ) $(OBJB) gnltester.c -o TEST

all: $(NAME) 
	
$(NAME): $(OBJ) bonus
	ar rc $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJB)
	ar rc $(NAME) $(OBJB) $(OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME} 
	rm -f TEST


re: fclean
	make all
