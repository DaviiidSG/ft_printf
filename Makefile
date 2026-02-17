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
PRINTF_H = ft_printf.h

# Source and object files
SRC = ft_printf.c ft_search_specifier.c ft_parser.c\
	ft_print_char.c ft_print_str.c ft_print_ptr.c\
	ft_putnbr_base.c

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
all: libft_compile $(NAME)
	@echo "$(GREEN) Listo $(RESET)"

# Compile libft.a using its own makefile
libft_compile:
	@echo "$(CYAN) Compilando libft... $(RESET)"
	@make -sC $(LIBFT_DIR)

# Creates ft_printf library
$(NAME): $(OBJ)
	@echo "$(CYAN) Compilando archivos objeto y empaquetandolos en $(NAME)... $(RESET)"
	@$(AR) $@ $^

# Creates .o files inside a dir
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/$(PRINTF_H)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(SRC_DIR) -I$(LIBFT_DIR)

# Delete .o files
clean:
	@echo "$(YELLOW) Borrando archivos objeto... $(RESET)"
	@$(RM) $(OBJ_DIR)
	@make clean -sC $(LIBFT_DIR)

# Delete .o and .a files
fclean:
	@echo "$(RED) Borrando archivos objeto y librerias... $(RESET)"
	@$(RM) $(NAME) $(OBJ_DIR)
	@make fclean -sC $(LIBFT_DIR)

# Remake the entire project
re: fclean all
