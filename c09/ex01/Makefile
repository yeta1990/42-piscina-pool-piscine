
SRCS	= srcs/ft_putchar.c \
		  srcs/ft_swap.c \
		  srcs/ft_putstr.c \
		  srcs/ft_strlen.c \
		  srcs/ft_strcmp.c \

INCS	= includes/

CC		= gcc 

OBJS	= ${SRCS:.c=.o}

CFLAGS	= -Wall -Wextra -Werror

NAME	= libft.a

RM		= rm -f

.c.o:		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME}:	${OBJS}	
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
