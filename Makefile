NAME	= push_swap

CC		= cc
CFLAGS	= -g -Wall -Wextra -Werror

LIBDIR	= ./libft
LIBFT	= ${LIBDIR}/libft.a

SRCS        :=      main.c error_free.c swaps.c push.c rotate.c rrotate.c tests.c \
					cost_calc.c operations.c go.c utils.c small_utils.c
OBJS        := $(SRCS:.c=.o)

%.o : %.c
	${CC} ${CFLAGS} -o $@ -c $< -I${LIBDIR}

${NAME}	: ${LIBFT} ${OBJS}
		${CC} ${LINKS} -o $@ ${OBJS} -L . ./libft/libft.a

${LIBFT}:
		make -C $(LIBDIR) all

all		: ${NAME}

bonus	: all

clean	:
		make -C ${LIBDIR} clean
		rm -f ${OBJS} ${OBJS_B}

fclean	: clean
		make -C ${LIBDIR} fclean
		rm -f ${NAME}

re		: fclean all

.PHONY: all, clean, fclean, bonus, re
