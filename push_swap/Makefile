#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apalanic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 11:03:28 by apalanic          #+#    #+#              #
#    Updated: 2016/11/25 11:07:05 by apalanic         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap
NAME_C = checker

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB = -L ./libft/ -lft

SRCDIR = ./swap/
SRC_SWAP =	main.c \
			stack_push.c \
			stack_reverse.c \
			stack_rotate.c \
			stack_sort.c \
			stack_swap.c \
			stack_manager.c \
			array_managment.c \
			check.c \
			utils.c \

OBJ_PATH = ./obj_swap/
OBJ_SWAP = $(SRC_SWAP:.c=.o)
SRC = $(addprefix $(SRCDIR), $(SRC_SWAP))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_SWAP))

SRCDIR_C = ./src_checker/
SRC_CHECK =	checker.c \
			comands.c \
			main.c \
			stack_manager.c \
			stack_push.c \
			stack_rev.c \
			stack_rotate.c \
			stack_swap.c \
			utils.c \

OBJ_PATH_C = ./obj_check/
OBJ_CHECK = $(SRC_CHECK:.c=.o)
SRC_C = $(addprefix $(SRCDIR_C), $(SRC_CHECK))
OBJ_C = $(addprefix $(OBJ_PATH_C), $(OBJ_CHECK))

all: $(NAME) $(NAME_C)

sswap: $(NAME)

check: $(NAME_C)

$(NAME): $(OBJ)
	@echo "push_swap : compiling..."
	@make -C libft/
	@gcc $(FLAGS) -o $@ $(OBJ) $(LIB)
	@echo "push_swap : compiliation complit!"
$(NAME_C): $(OBJ_C)
	@echo "checker: compiling..."
	@make -C libft/
	@gcc $(FLAGS) -o $@ $(OBJ_C) $(LIB)

$(OBJ_PATH)%.o: $(SRCDIR)%.c
	@mkdir $(OBJ_PATH) 
	@gcc $(FLAGS) -o $@ -c $<
$(OBJ_PATH_C)%.o: $(SRCDIR_C)%.c
	@mkdir $(OBJ_PATH_C) 
	@gcc $(FLAGS) -o $@ -c $<

clean:
	@make -C libft/ clean
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 
	rm -f $(OBJ_C)
	@rmdir $(OBJ_PATH_C) 
	@echo "Objects deleted"

fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME) $(NAME_C)
	@echo "push_swap and checker binaries deleted"

re: fclean all
	@make -C libft/ re

.PHONY: all, swap, check, clean, fclean, re 
# OBJDIR_S = ./obj/
# OBJ_SWAP = $(addprefix $(OBJDIR),$(SRC:.c=.o))


# all: obj $(NAME)

# obj:
# 	mkdir -p $(OBJDIR)

# $(OBJDIR)%.o:$(SRCDIR)%.c
# 	gcc $(FLAGS) -o $@ -c $<

# $(NAME): $(OBJ)
# 	gcc -o $(NAME) $(OBJ) $(LIB)

# clean:
# 	/bin/rm -rf $(OBJDIR)

# fclean: clean
# 	/bin/rm -f $(NAME)

# re: fclean all
