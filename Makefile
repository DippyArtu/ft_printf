# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/06 17:45:47 by jsalome           #+#    #+#              #
#    Updated: 2020/07/29 20:28:24 by Artur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = ./srcs/
SRC = 	ft_printf.c\
		processing.c\
		process_flags.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ = $(SRC:.c=.o)
OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

INC_DIR = ./includes/
INC = 	ft_printf.h

INCS = $(addprefix $(INC_DIR), $(INC))

LIB_OBJ = *.o
LIB_OBJ_DIR = ./libft/obj/
LIB_OBJS = $(addprefix $(LIB_OBJ_DIR), $(LIB_OBJ))
LIB_SRC_DIR = ./libft/srcs/
LIB_INC = libft.h get_next_line.h
LIB_INC_DIR = ./includes/
LIB_INCS = $(addprefix $(LIB_INC_DIR), $(LIB_INC))

FLAGS = -g -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIB_INC_DIR)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIB_OBJS) $(OBJS)
		cp libft/libft.a ./$(NAME)
		@ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
$(OBJ_DIR):
		@mkdir -p $@
		@mkdir -p $(LIB_OBJ_DIR)

$(LIB_OBJ_DIR)%.o: $(LIB_SRC_DIR)%.c $(LIB_INCS)
		@make -C libft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
		clang $(FLAGS) -o $@ -c $<

clean:
		@make clean -C libft
		@rm -f $(OBJS)
		@rm -rf $(OBJ_DIR)

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
