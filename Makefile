# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 12:41:15 by mguerga           #+#    #+#              #
#    Updated: 2022/12/29 15:55:07 by mguerga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

CC = gcc

CFLAGS = -Werror -Wall -Wextra -D BUFFER_SIZE=10000

SRC = get_next_line.c get_next_line_utils.c

SRCB =

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

test : fclean $(OBJ) $(OBJB)
	$(CC) $(CFLAGS) $(OBJ) $(OBJB) gnltester.c -o TEST

all : $(OBJ) bonus
	$(CC) $(CFLAGS) $(OBJ) $(NAME)

bonus : $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) $(NAME)

clean :
	rm -f *.o

fclean : clean
	rm -f ${NAME} 
	rm -f TEST


re : fclean
	make all
