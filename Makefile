NAME = libftprintf.a

SRCS = src/ft_printf.c \
	   src/ft_cis.c \
	   src/ft_ishexamay.c \
	   src/ft_ishexamin.c \
	   src/ft_ispointer.c \
	   src/ft_putstr.c \
	   src/ft_strlen.c \
	   src/ft_isunsigned.c \

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wextra -Werror -Wall

HEADER = inc/ft_printf.h

%.o: %.c ${HEADER}
	gcc ${FLAGS} -I./ -c $< -o $@

all : ${NAME}

${NAME} : ${OBJS} ${HEADER}
	ar -rcs ${NAME} ${OBJS}

clean :
	rm -f ${OBJS}
	
fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
