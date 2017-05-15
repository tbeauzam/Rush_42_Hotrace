# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 13:59:02 by tbeauzam          #+#    #+#              #
#    Updated: 2017/05/14 19:16:23 by tbeauzam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	hotrace
CC			=	clang
FLAGS		=	-O3 -Wall -Wextra -Werror
SRC_NAME	=	main_hotrace.c \
				hotrace_get_data.c \
				hotrace_sorting.c \
				hotrace_table.c \
				hotrace_requests.c \
				ft_strlen.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_strdup.c \
				ft_strdel.c
OBJ_NAME	=	$(SRC_NAME:.c=.o)
SRC_PATH	=	./src
OBJ_PATH	=	./obj
SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC			=	-I ./include
INC_FILE	=	./include/hotrace.h

.PHONY: all, clean, fclean, re

all:				$(NAME)

$(NAME):			$(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)
	@echo "hotrace executable Done!"

$(OBJ_PATH)/%.o:		$(SRC_PATH)/%.c $(INC_FILE)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || :
	@echo "Objects of hotrace Cleaned!"

fclean:				clean
	@rm -f $(NAME)
	@echo "Executable hotrace Cleaned!"
	@echo "Everything have been exterminated, Sir!"

re:					fclean all
