SRCS = ft_atoi.c ft_isdigit.c ft_isprint.c ft_isalpha.c ft_isalnum.c \

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

LIBC = ar rcs

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
${RM} ${OBJS}

fclean: clean
${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
