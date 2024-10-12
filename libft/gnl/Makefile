#Buffer
n = 1

# Compiler and Flags
CC = cc
# CFLAGS = -Wall -Wextra -Werror -g -O0 -D BUFFER_SIZE=$(n)
CFLAGS = -Wall -Wextra -Werror -g -O0

# Source Files (Find all .c files in the current directory and libft directory)
SRC =	get_next_line_bonus.c

# Object Files
OBJ = $(SRC:.c=.o)

# Library Name
NAME = gnl.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

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
