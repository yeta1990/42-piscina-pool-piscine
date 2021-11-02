
SRCS	= main.c dict_ops.c utils.c handle_error.c translator.c translator_au.c

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

NAME	= rush-02

RM		= rm -f

${NAME}:
		${CC} ${CFLAGS} ${SRCS} -o ${NAME}

all:		${NAME}

fclean:		
			${RM} ${NAME}

.PHONY:		all fclean 
