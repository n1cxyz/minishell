# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 16:59:25 by wlucke            #+#    #+#              #
#    Updated: 2024/06/25 15:58:27 by wlucke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for combined libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Paths to individual libraries
BASE_LIB = base/libft_base.a
GNL_LIB = gnl/gnl.a
PRINTF_LIB = printf/printf.a

# Combined library name
NAME = libft.a

all: $(NAME)

$(NAME): $(BASE_LIB) $(GNL_LIB) $(PRINTF_LIB)
	ar -x $(BASE_LIB)
	ar -x $(GNL_LIB)
	ar -x $(PRINTF_LIB)
	ar -rcs $(NAME) *.o
	rm -f *.o

$(BASE_LIB):
	$(MAKE) -C base

$(GNL_LIB):
	$(MAKE) -C gnl

$(PRINTF_LIB):
	$(MAKE) -C printf

clean:
	$(MAKE) -C base clean
	$(MAKE) -C gnl clean
	$(MAKE) -C printf clean
	rm -f *.o

fclean: clean
	$(MAKE) -C base fclean
	$(MAKE) -C gnl fclean
	$(MAKE) -C printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


## OLD
# # Compiler and Flags
# CC = cc
# CFLAGS = -Wall -Wextra -Werror -g -O0

# # Path to the libft directory
# LIBFT_PATH = libft/base
# LIBFT_NAME = libft
# LIBFT_LIB = $(LIBFT_PATH)/$(LIBFT_NAME).a

# # Path to the printf directory
# PRINTF_PATH = libft/printf
# PRINTF_NAME = printf
# PRINTF_LIB = $(PRINTF_PATH)/$(PRINTF_NAME).a

# # Path to the get next line directory
# GNL_PATH = libft/gnl
# GNL_NAME = gnl
# GNL_LIB = $(GNL_PATH)/$(GNL_NAME).a

# # Library Name
# NAME = libft.a

# all: $(NAME)

# $(LIBFT_LIB):
# 	$(MAKE) -C $(LIBFT_PATH)
    
# $(PRINTF_LIB):
# 	$(MAKE) -C $(PRINTF_PATH)
    
# $(GNL_LIB):
# 	$(MAKE) -C $(GNL_PATH)

# $(NAME): $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_LIB)
# 	ar rcs $(NAME) $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_LIB)

# .c.o:
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Clean up object files
# clean:
# 	rm -f $(OBJ)
# 	$(MAKE) -C $(LIBFT_PATH) clean
# 	$(MAKE) -C $(PRINTF_PATH) clean
# 	$(MAKE) -C $(GNL_PATH) clean

# # Clean up library and object files
# fclean: clean
# 	rm -f $(NAME)
# 	$(MAKE) -C $(LIBFT_PATH) fclean
# 	$(MAKE) -C $(PRINTF_PATH) fclean
# 	$(MAKE) -C $(GNL_PATH) fclean

# # Rebuild the project
# re: fclean all

# # Mark these targets as phony (not associated with a file)
# .PHONY: all clean fclean re



## VERY OLD
# # Compiler and Flags
# CC = cc
# CFLAGS = -Wall -Wextra -Werror -g -O0

# # Path to the libft directory
# LIBFT_PATH = base
# LIBFT_NAME = libft
# LIBFT_LIB = $(LIBFT_PATH)/$(LIBFT_NAME).a

# # Path to the get next line directory
# PRINTF_PATH = printf
# PRINTF_NAME = printf
# PRINTF_LIB = $(LIBFT_PATH)/$(LIBFT_NAME).a

# # Path to the get next line directory
# GNL_PATH = gnl
# GNL_NAME = gnl
# GNL_LIB = $(LIBFT_PATH)/$(LIBFT_NAME).a

# # Library Name
# NAME = libft.a

# all: $(NAME)

# $(LIBFT_LIB):
#     $(MAKE) -C $(LIBFT_PATH)
    
# $(PRINTF_LIB):
#     $(MAKE) -C $(PRINTF_PATH)
    
# $(GNL_LIB):
#     $(MAKE) -C $(GNL_PATH)

# $(NAME): $(OBJ)
# 	ar rcs $(NAME) $(OBJ)
# # $(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# .c.o:
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Clean up object files
# clean:
# 	rm -f $(OBJ)

# # Clean up library and object files
# fclean: clean
# 	rm -f $(NAME)

# # Rebuild the project
# re: fclean all

# # Mark these targets as phony (not associated with a file)
# .PHONY: all clean fclean re
