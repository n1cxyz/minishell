# # Makefile for builtins

# # Compiler and Flags
# CC = cc
# CFLAGS = -Werror -Wall -Wextra -g -O0

# # Paths
# SRC_DIR = 
# INCLUDE_DIR = ../../../include

# # Builtin Executable Names
# # BUILTINS = echo_n echo env pwd
# BUILTINS = echo env pwd

# # Include Paths
# INCLUDES = -I$(INCLUDE_DIR)

# # Targets
# all: $(BUILTINS)

# # Build each builtin executable (directly specifying object file)
# # echo_n: echo_n.o
# # 	$(CC) $(CFLAGS) $(INCLUDES) echo_n.o -o echo_n

# echo: echo.o
# 	$(CC) $(CFLAGS) $(INCLUDES) echo.o -o echo

# env: env.o
# 	$(CC) $(CFLAGS) $(INCLUDES) env.o -o env

# pwd: pwd.o
# 	$(CC) $(CFLAGS) $(INCLUDES) pwd.o -o pwd

# # Compile .o files from .c files
# # echo_n.o: $(SRC_DIR)/echo_n.c
# # 	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/echo_n.c -o echo_n.o

# echo.o: $(SRC_DIR)/echo.c
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/echo.c -o echo.o

# env.o: $(SRC_DIR)/env.c
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/env.c -o env.o

# pwd.o: $(SRC_DIR)/pwd.c
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/pwd.c -o pwd.o

# # Clean up object files and executables
# clean:
# #	rm -f echo_n.o echo.o env.o pwd.o
# 	rm -f echo.o env.o pwd.o

	
# fclean:
# #	rm -f echo_n echo env pwd
# 	rm -f echo env pwd

# # Rebuild the project
# re: clean all

# # Mark these targets as phony (not associated with a file)
# .PHONY: all clean re

##=============================================================

# # Makefile for builtins

# # Compiler and Flags
# CC = cc
# CFLAGS = -Werror -Wall -Wextra -g -O0

# # Paths
# INCLUDE_DIR = ../../../include

# # Builtin Executable Names
# BUILTINS = echo env pwd

# # Include Paths
# INCLUDES = -I$(INCLUDE_DIR)

# # Targets
# all: $(BUILTINS)

# # Build each builtin executable
# echo: echo.o
# 	$(CC) $(CFLAGS) $(INCLUDES) echo.o -o echo

# env: env.o
# 	$(CC) $(CFLAGS) $(INCLUDES) env.o -o env

# pwd: pwd.o
# 	$(CC) $(CFLAGS) $(INCLUDES) pwd.o -o pwd

# # Compile .o files from .c files
# echo.o: echo.c
# 	$(CC) $(CFLAGS) $(INCLUDES) -c echo.c -o echo.o

# env.o: env.c
# 	$(CC) $(CFLAGS) $(INCLUDES) -c env.c -o env.o

# pwd.o: pwd.c
# 	$(CC) $(CFLAGS) $(INCLUDES) -c pwd.c -o pwd.o

# # Clean up object files and executables
# clean:
# 	rm -f *.o

# fclean: clean
# 	rm -f echo env pwd

# # Rebuild the project
# re: fclean all

# # Mark these targets as ph


# Makefile for builtins

# Compiler and Flags
CC = cc
CFLAGS = -Werror -Wall -Wextra -g -O0

# Paths
LIBFT_DIR = ../../libft
INCLUDE_DIR = ../../include

# Builtin Executable Names
BUILTINS = echo env pwd

# Include Paths
INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR)

# Library Paths
LIBFT = $(LIBFT_DIR)/libft.a

# Targets
all: $(BUILTINS)

# Build each builtin executable
echo: echo.o
	$(CC) $(CFLAGS) $(INCLUDES) echo.o -o echo $(LIBFT)

env: env.o
	$(CC) $(CFLAGS) $(INCLUDES) env.o -o env $(LIBFT)

pwd: pwd.o
	$(CC) $(CFLAGS) $(INCLUDES) pwd.o -o pwd $(LIBFT)

# Compile .o files from .c files
echo.o: echo.c
	$(CC) $(CFLAGS) $(INCLUDES) -c echo.c -o echo.o

env.o: env.c
	$(CC) $(CFLAGS) $(INCLUDES) -c env.c -o env.o

pwd.o: pwd.c
	$(CC) $(CFLAGS) $(INCLUDES) -c pwd.c -o pwd.o

# Clean up object files and executables
clean:
	rm -f *.o

fclean: clean
	rm -f echo env pwd

# Rebuild the project
re: fclean all

# Mark these targets as phony (not associated with a file)
.PHONY: all clean fclean re
