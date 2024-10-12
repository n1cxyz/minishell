# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlucke <wlucke@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 16:59:25 by wlucke            #+#    #+#              #
#    Updated: 2024/06/29 13:26:08 by wlucke             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O0

# Source Files (Find all .c files in the current directory and libft directory)
SRC =	ft_printf.c \
		ft_put_addr.c \
		ft_putarg.c \
		ft_put_hex.c \
		ft_put_nbr.c \
		ft_put_unbr.c \
		ft_help.c

# Object Files
OBJ = $(SRC:.c=.o)

# Library Name
NAME = printf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	# $(CC) $(CFLAGS) -o $(NAME) $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJ)

# Clean up library and object files
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

# Mark these targets as phony (not associated with a file)
.PHONY: all clean fclean re
