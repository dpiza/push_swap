# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 22:45:09 by dpiza             #+#    #+#              #
#    Updated: 2021/11/24 23:44:42 by dpiza            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap
CHECKER 		= checker

SRCS_DIR 		= ./src
OBJS_DIR 		= ./obj
INCLUDES_DIR 	= ./includes

LIBFT_DIR 		= ./libft
LIBFT 			= $(LIBFT_DIR)/libft.a

CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror $(LEAKCHECK)
LEAKCHECK 		= -g -fsanitize=address
LFLAGS 			= -L./libft -lft

RM 				= rm -f
NORM			= norminette

INCLUDES_FILES =	push_swap.h \
					defines.h

INCLUDES 		= $(addprefix $(INCLUDES_DIR)/, $(INCLUDES_FILES))

# **************************************************************************** #
#                                 PUSH_SWAP                                    #
# **************************************************************************** #

SRCS = 				push_swap.c \
					init.c \
					verification.c \
					algos.c \
					utils.c \
					op_common.c \
					op_stack_a.c \
					op_stack_b.c \
					op_stack_ab.c 

OBJS 			= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

# **************************************************************************** #
#                                 CHECKER                                      #
# **************************************************************************** #

CHECKER_SRC =		checker.c \
					init.c \
					verification.c \
					algos.c \
					utils.c \
					op_common.c \
					op_stack_a.c \
					op_stack_b.c \
					op_stack_ab.c 

CHECKER_OBJS 	= $(addprefix $(OBJS_DIR)/, $(notdir $(CHECKER_SRC:.c=.o)))

# **************************************************************************** #
#                                   MAKE                                       #
# **************************************************************************** #

bonus: 			all

all: 			$(NAME) $(CHECKER)

$(NAME): 		$(LIBFT) $(OBJS) $(INCLUDES)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

$(CHECKER): 	$(LIBFT) $(CHECKER_OBJS) $(INCLUDES)
				$(CC) $(CFLAGS) -o $(CHECKER) $(CHECKER_OBJS) $(LFLAGS)

$(LIBFT):
				@make -C $(LIBFT_DIR) printf --no-print-directory

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES_DIR) $(INCLUDES)
				@mkdir -p $(OBJS_DIR)
				@$(CC) $(FLAGS) -I $(INCLUDES_DIR) -c $< -o $@

.PHONY:			all bonus

# **************************************************************************** #
#                                   CLEAN                                      #
# **************************************************************************** #

clean:
				@make -C $(LIBFT_DIR) clean --no-print-directory
				@$(RM) $(OBJS)

fclean: 		clean
				@make -C $(LIBFT_DIR) fclean --no-print-directory
				@$(RM) $(NAME)
				@rm -rf $(OBJS_DIR)

re: 			fclean all

.PHONY:			clean fclean re

# **************************************************************************** #
#                                NORMINETTE                                    #
# **************************************************************************** #

norm:
				@$(NORM) $(SRCS_DIR)/*.c $(INCLUDES_DIR)/*.h

.PHONY:			norm

# **************************************************************************** #
#                                   TESTS                                      #
# **************************************************************************** #

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --log-file=valgrind-out.txt ./push_swap 1 3 2

.PHONY: 		Valgrind