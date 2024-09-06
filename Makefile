NAME		= minishell
CC			= cc
BIN			= bin
SRC			= src/parser/parsing_utils.c src/parser/parsing.c src/debug.c src/main.c \
			src/tokenize/tokenize.c src/tokenize/handlers.c src/token.c src/utils.c
OBJS		= $(SRC:src/%c=$(BIN)/%o)
INCS		= include
LIBFT		= libft
LIBFT_INCS	= $(LIBFT)
CFLAGS		= -Wall -Werror -Wextra -g
LFLAGS		= -L$(LIBFT) -lft
IFLAGS		= -I$(INCS) -I$(LIBFT_INCS)
RM			= rm -rf
VALGRIND	= @valgrind --leak-check=full --show-leak-kinds=all
#--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

all: $(NAME)

$(NAME): ${BIN} ${OBJS} | ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} ${LFLAGS} -o ${NAME}

$(BIN)/%o: src/%c
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c $< ${IFLAGS} -o $@

$(BIN):
	mkdir -p $(BIN)

$(LIBFT):
	@make all -C $(LIBFT) --no-print-directory

clean:
	$(RM) $(BIN)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT) --no-print-directory

re: fclean all

run:
	./${NAME}

rerun: re run

test: ${NAME}
	${VALGRIND} ./${NAME}

.PHONY: $(LIBFT) re all clean fclean run rerun test