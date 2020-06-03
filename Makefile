# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/03 08:49:40 by ubuntu            #+#    #+#              #
#    Updated: 2020/06/03 11:19:02 by ubuntu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	prime_numbers

CC					=	clang
C_FLAGS				=	-g -Wall -Werror -Wextra

LIBFT_FOLDER		=	lib/lib_ft
LIBFT				=	$(LIBFT_FOLDER)/libft.a
LIBFTPRINTF_FOLDER	=	lib/lib_ftprintf
LIBFTPRINTF			=	$(LIBFTPRINTF_FOLDER)/libftprintf.a

LIB					=	-L $(LIBFT_FOLDER) -l ft -L $(LIBFTPRINTF_FOLDER) -l ftprintf
INCLUDES			=	-I $(LIBFT_FOLDER) -I $(LIBFTPRINTF_FOLDER)
SRC_FOLDER			=	src
MAIN				=	$(SRC_FOLDER)/prime_numbers.c
HEADER				=	$(SRC_FOLDER)/prime_numbers.h

SRC					=	memory.c

OBJ_FOLDER			=	obj
OBJ					=	$(addprefix $(OBJ_FOLDER)/, $(patsubst %.c, %.o, $(SRC)))

all: $(LIBFT) $(LIBFTPRINTF) $(NAME)

$(NAME): $(OBJ) $(MAIN)
	@echo "$(NAME) created."
	@$(CC) $(C_FLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(MAIN) $(LIB)

$(OBJ): $(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c $(HEADER) | $(OBJ_FOLDER)
	@echo "$(@) created."
	@$(CC) $(C_FLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFT):
	make -C $(LIBFT_FOLDER)

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_FOLDER)

$(OBJ_FOLDER):
	mkdir $(OBJ_FOLDER)

clean:
	make -C $(LIBFT_FOLDER) clean
	make -C $(LIBFTPRINTF_FOLDER) clean
	\rm -f $(OBJ_FOLDER)/*.o

fclean: clean
	make -C $(LIBFT_FOLDER) fclean
	make -C $(LIBFTPRINTF_FOLDER) fclean
	\rm -f $(LIBFT_FOLDER)/libft.a
	\rm -f $(LIBFTPRINTF_FOLDER)/libftprintf.a
re:

.phony: all clean fclean
