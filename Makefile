# Makefile for minishell

# Compiler and Flags
CC = cc
CFLAGS = -g -O0
# CFLAGS = -Werror -Wall -Wextra -g -O0

# Paths
SRC_DIR = src
INCLUDE_DIR = include
PIPEX_DIR = pipex
LIBFT_DIR = libft
BUILTINS_DIR = src/builtins

# Library and Executable Names
PIPEX_LIB = $(PIPEX_DIR)/libpipex.a
LIBFT = $(LIBFT_DIR)/libft.a
PIPEX_EXEC = $(PIPEX_DIR)/pipex
NAME = minishell

# Source Files for minishell (excluding builtins)
MINISHELL_SRC =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/signals.c \
		$(SRC_DIR)/env.c \
		$(SRC_DIR)/executor.c \
		$(SRC_DIR)/serializer.c \
		$(SRC_DIR)/serializer_utils.c \
		$(SRC_DIR)/expander/expand_utils.c \
		$(SRC_DIR)/expander/expand.c \
		$(SRC_DIR)/expander/expand_search.c \
		$(SRC_DIR)/parser/parsing_utils.c \
		$(SRC_DIR)/parser/parsing_utils_2.c \
		$(SRC_DIR)/parser/parsing.c \
		$(SRC_DIR)/tokenize/handlers.c \
		$(SRC_DIR)/tokenize/tokenize.c \
		$(SRC_DIR)/fill_struct/fill_struct.c \
		$(SRC_DIR)/fill_struct/fill_struct_utils.c \
		$(SRC_DIR)/fill_struct/handle_operators.c \
		$(SRC_DIR)/debug.c \
		$(SRC_DIR)/token.c \
		$(SRC_DIR)/utils1.c \
		$(SRC_DIR)/utils2.c \
		$(SRC_DIR)/utils3.c \
		$(SRC_DIR)/utils_error.c \
		$(SRC_DIR)/builtins.c \
		$(SRC_DIR)/builtins2.c \
		$(SRC_DIR)/env_add.c \
		$(SRC_DIR)/env_delete.c \
		$(SRC_DIR)/env_path.c \
		$(SRC_DIR)/env_pipex.c \
		$(SRC_DIR)/open_pipe.c \
		$(SRC_DIR)/bonus/eval_cmds.c \
		$(SRC_DIR)/bonus/bonus_utils.c \
		$(SRC_DIR)/wildcard.c \
		$(SRC_DIR)/wildcard_utils.c \

# Object Files for minishell
MINISHELL_OBJ = $(MINISHELL_SRC:.c=.o)

# Include Paths
INCLUDES = -I$(INCLUDE_DIR) -I$(PIPEX_DIR)/include -I$(LIBFT_DIR)/base -I$(LIBFT_DIR)/gnl -I$(LIBFT_DIR)/printf

# Libraries
LIBS = -lreadline -lncurses

# Colors for Status Messages
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

# Targets
all: $(LIBFT) $(PIPEX_EXEC) $(NAME) builtins

# Compile minishell
$(NAME): $(MINISHELL_OBJ) $(PIPEX_LIB) $(LIBFT)
	@echo "$(YELLOW)Linking minishell...$(RESET)"
	$(CC) $(CFLAGS) $(MINISHELL_OBJ) $(PIPEX_LIB) $(LIBFT) -o $(NAME) $(LIBS)
	@echo "$(GREEN)Build complete!$(RESET)"

# Build pipex executable
$(PIPEX_EXEC):
	@echo "$(YELLOW)Building pipex...$(RESET)"
	@$(MAKE) -C $(PIPEX_DIR) all
	@echo "$(GREEN)Pipex build complete!$(RESET)"

# Build libft
$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft build complete!$(RESET)"

# Build builtins
builtins:
	@echo "$(YELLOW)Building builtins...$(RESET)"
	@$(MAKE) -C $(BUILTINS_DIR) all
	@echo "$(GREEN)Builtins build complete!$(RESET)"

# Compile object files for minishell
%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean up object files
clean:
	@echo "$(RED)Cleaning up object files...$(RESET)"
	@rm -f $(MINISHELL_OBJ)
	@$(MAKE) -C $(PIPEX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(BUILTINS_DIR) clean

# Clean up everything, including libraries and executables
fclean: clean
	@echo "$(RED)Removing executable and cleaning pipex and libft...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(PIPEX_DIR) fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(BUILTINS_DIR) fclean

# Rebuild the project
re: fclean all

# Mark these targets as phony (not associated with a file)
.PHONY: all clean fclean re builtins
