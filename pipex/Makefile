# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 09:33:41 by wlucke            #+#    #+#              #
#    Updated: 2024/09/25 09:33:43 by wlucke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O0

# Paths
SRC_DIR = src
INCLUDE_DIR = include
LIBFT_DIR = ../libft

# Library and Executable Names
LIBFT = $(LIBFT_DIR)/libft.a
NAME = pipex
LIB = libpipex.a

# Source Files
SRC =	$(SRC_DIR)/0_main.c \
		$(SRC_DIR)/1_init.c \
		$(SRC_DIR)/2_load.c \
		$(SRC_DIR)/2_load_cmds.c \
		$(SRC_DIR)/2_load_files.c \
		$(SRC_DIR)/2_load_redirections.c \
		$(SRC_DIR)/2_parse_env.c \
		$(SRC_DIR)/2_parse.c \
		$(SRC_DIR)/3_exec.c \
		$(SRC_DIR)/3_exec_read.c \
		$(SRC_DIR)/3_exec_read_heredoc.c \
		$(SRC_DIR)/3_exec_read_infile.c \
		$(SRC_DIR)/3_exec_open.c \
		$(SRC_DIR)/3_exec_cmd.c \
		$(SRC_DIR)/3_exec_expand_heredoc.c \
		$(SRC_DIR)/3_exec_pipe.c \
		$(SRC_DIR)/3_exec_pipe_start_setup.c \
		$(SRC_DIR)/3_exec_pipe_start_exec.c \
		$(SRC_DIR)/3_exec_pipe_wait.c \
		$(SRC_DIR)/3_exec_utils.c \
		$(SRC_DIR)/4_cleanup.c \
		$(SRC_DIR)/4_cleanup_free.c \
		$(SRC_DIR)/utils.c 

LIBS = -lreadline -lncurses

# Object Files
OBJ = $(SRC:.c=.o)

# Include Paths
INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/base -I$(LIBFT_DIR)/gnl -I$(LIBFT_DIR)/printf

# Colors for Status Messages
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

# Targets
all: $(NAME) $(LIB)

bonus: $(NAME)

# Explicitly add the target for creating the executable
$(NAME): $(LIBFT) $(OBJ)
	@echo "$(YELLOW)Linking executable...$(RESET)"
#		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(LIBS)
	@echo "$(GREEN)Executable build complete!$(RESET)"

$(LIB): $(OBJ)
	@echo "$(YELLOW)Creating static library...$(RESET)"
	ar rcs $(LIB) $(OBJ)
	@echo "$(GREEN)Static library created: $(LIB)$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft build complete!$(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean up object files
clean:
	@echo "$(RED)Cleaning up object files...$(RESET)"
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Clean up library, executable, and object files
fclean: clean
	@echo "$(RED)Removing executable, static library, and cleaning libft...$(RESET)"
	@rm -f $(NAME) $(LIB)
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild the project
re: fclean all

# Mark these targets as phony (not associated with a file)
.PHONY: all clean fclean re bonus