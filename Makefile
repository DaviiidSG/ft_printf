# Config
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

# File paths
SRC_DIR = ./src
OBJ_DIR = ./objs
HEADERS = ft_printf.h $(SRC_DIR)/ft_printf_internal.h

# Source files
SRC = ft_printf.c buff_handlers.c parser.c insert_char.c insert_str.c\
	insert_ptr.c insert_int.c insert_uint.c insert_hex.c

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

# Creates libftprintf library
$(NAME): $(OBJ)
	@echo "$(CYAN)Creating $(NAME)$(RESET)"
	@$(AR) $@ $(OBJ)
	@echo "$(GREEN)Ready$(RESET)"

# Creates .o files inside a dir
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@echo "$(CYAN)Compiling $< $(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Delete .o files
clean:
	@echo "$(YELLOW)Deleting objects...$(RESET)"
	@$(RM) $(OBJ_DIR)

# Delete .o and .a files
fclean: clean
	@echo "$(RED)Deleting library...$(RESET)"
	@$(RM) $(NAME)

# Remake the entire project
re: fclean all
