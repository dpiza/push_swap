SRCS_DIR = ./src
OBJS_DIR = ./obj
INCLUDES_DIR = ./includes
LIBFT_DIR = ./libft

CFLAGS = -Wall -Wextra -Werror
LEAKCHECK = -g -fsanitize=address
CC = gcc $(CFLAGS)
LFLAGS = -L./libft -lft
RM = rm -f

NAME = push_swap

SRCS_FILES = main.c operations.c err.c push_swap.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS_FILES = $(SRCS_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

INCLUDES_FILES = push_swap.h defines.h
INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(INCLUDES_FILES))

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

bonus: all

Valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all \
	--log-file=valgrind-out.txt ./push_swap

$(NAME): $(LIBFT) $(OBJS) $(INCLUDES)
	$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR) printf

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES_DIR) $(INCLUDES)
	mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -I $(INCLUDES_DIR) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	rm -rf $(OBJS_DIR)

re: fclean all

.PHONY:	all clean fclean re bonus
.PHONY: Valgrind