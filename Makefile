# Config
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -rf

# File paths
SRC_DIR = ./src
OBJ_DIR = ./objs
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_H = $(SRC_DIR)/ft_printf.h

# Source and object files
SRC = ft_printf.c ft_search_specifier.c ft_parser.c \
	ft_print_char.c ft_print_str.c ft_print_ptr.c \
	ft_putnbr_base.c ft_print_int.c ft_print_uint.c \
	ft_print_hex.c ft_print_percent.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# Colors
YELLOW = \033[1;33m
GREEN = \033[1;32m
RED = \033[1;31m
CYAN = \033[1;36m
RESET = \033[0m

# Indicates that the following rules are not actual files
.PHONY: all clean fclean re

# Default rule to compile
all: $(NAME)
	@echo "$(GREEN)Ready$(RESET)"

# Creates ft_printf library
$(NAME): $(LIBFT) $(OBJ)
	@$(AR) $@ $(OBJ)

$(LIBFT):
	@echo "$(CYAN)Compiling...$(RESET)"
	@make -sC $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)
	@make fclean -sC $(LIBFT_DIR)

# Creates .o files inside a dir
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(PRINTF_H)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(SRC_DIR) -I$(LIBFT_DIR)

# Delete .o files
clean:
	@echo "$(YELLOW)Deleting objects...$(RESET)"
	@$(RM) $(OBJ_DIR)

# Delete .o and .a files
fclean:
	@echo "$(RED)Deleting objects and libraries...$(RESET)"
	@$(RM) $(NAME) $(OBJ_DIR)

# Remake the entire project
re: fclean all
