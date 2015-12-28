# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/21 17:34:59 by aderragu          #+#    #+#              #
#    Updated: 2015/12/28 11:37:38 by tvisenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

SRC_PATH = ./src/
SRC_NAME = 	main.c\
			check_file.c\
			points_assignment.c\
			initfile.c\
			creat_display.c

OBJ = $(SRC_NAME:.c=.o) $(TEST_NAME:.c=.o) $(LIB_NAME:.c=.o)

LIB_PATH = ./lib/
LIB_NAME = 	ft_putstr.c\
	 		ft_sqrt.c\
	  		ft_strlen.c\
			ft_round.c\
			ft_bsq.c\
			ft_memset.c\
			ft_abs.c


INC_PATH = ./inc/
INC_NAME = fillit.h

NAME = fillit

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))
INC = $(addprefix $(INC_PATH),$(INC_NAME))

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) $(LIB) -I $(INC) -o $(NAME)
	@echo "Compilation success"
clean:
	@rm -rf $(OBJ)
	@echo "Delete .o"
fclean: clean
	@rm -rf $(NAME)
	@echo "Delete fillit"
re: fclean all
