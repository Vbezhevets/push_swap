NAME  = push_swap
NAME_B= checker

CC    = cc
CFLAGS= -Wall -Wextra -Werror -g
RM    = rm -rf

LIBDIR= ./libft
LIBFT = ${LIBDIR}/libft.a

SRCSDIR     = srcs
SRCS  = \
			${SRCSDIR}/main.c \
			${SRCSDIR}/error_free.c \
			${SRCSDIR}/swaps.c \
			${SRCSDIR}/push.c \
			${SRCSDIR}/rotate.c \
			${SRCSDIR}/rrotate.c \
			${SRCSDIR}/cost_calc.c \
			${SRCSDIR}/operations.c \
			${SRCSDIR}/go.c \
			${SRCSDIR}/utils.c \
			${SRCSDIR}/small_utils.c \
			${SRCSDIR}/pair.c \

OBJSDIR     = ${SRCSDIR}/objs
OBJS        = $(SRCS:${SRCSDIR}/%.c=${OBJSDIR}/%.o)

SRCSDIR_B   = srcs_bonus
SRCS_B= \
		${SRCSDIR_B}/main_b.c \
		${SRCSDIR_B}/exec_b.c \
		${SRCSDIR_B}/push_b.c \
		${SRCSDIR_B}/utils_b.c \
		${SRCSDIR_B}/error_free_b.c \
		${SRCSDIR_B}/rotate_b.c \
		${SRCSDIR_B}/rrotate_b.c \
		${SRCSDIR_B}/swaps_b.c

OBJSDIR_B   = ${SRCSDIR_B}/objs
OBJS_B= $(SRCS_B:$(SRCSDIR_B)/%.c=${OBJSDIR_B}/%.o)

all   : $(NAME)

bonus : $(NAME_B)

$(NAME)     : $(OBJS)
		make --no-print-directory -C ${LIBDIR} all
		$(CC) $(CFLAGS) -o $@ $^ $(LINKS) -L. ${LIBFT}

$(NAME_B)   : $(OBJS_B)
		make --no-print-directory -C ${LIBDIR} all

		$(CC) $(CFLAGS) -o $(NAME_B) $^ $(LINKS) -L. ${LIBFT}

${OBJSDIR}/%.o : ${SRCSDIR}/%.c
		@mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@ -I ./includes

${OBJSDIR_B}/%.o : ${SRCSDIR_B}/%.c
		@mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@ -I ./includes

clean :
		make --no-print-directory -C ${LIBDIR} clean
		$(RM) $(OBJSDIR) $(OBJSDIR_B)

fclean:
		make --no-print-directory -C ${LIBDIR} fclean
		$(RM) $(OBJSDIR) $(OBJSDIR_B) $(NAME) $(NAME_B)

re    : fclean all

.PHONY: all clean fclean bonus re
