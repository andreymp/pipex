NAME =	pipex

CC =	gcc
CFLAGS =	-g -Wall -Wextra -Werror -MMD

RM =	rm -rf

SRC =   mandatory/init.c	\
		mandatory/pipex.c	\
		mandatory/utils.c	\
		mandatory/main.c	\

SRC_B =	bonus/init_bonus.c	\
		bonus/main_bonus.c	\
		bonus/pipex_bonus.c	\
		bonus/utils_bonus.c	\
		bonus/get_next_line.c \
		bonus/get_next_line_utils.c \

INC = 	-I libft/libft.h 	\
		-I mandatory/pipex.h	\
		-I bonus/pipex_bonus.h \
		-I bonus/get_next_line.h \

OBJS =	$(SRC:.c=.o)
DEP =	$(SRC:.c=.d)

OBJS_B =	$(SRC_B:.c=.o)
DEP_B =		$(SRC_B:.c=.d)

LD_FLAGS =	-L libft

.PHONY :	all clean re fclean

.c.o :		
		${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}


$(NAME):	$(OBJS)
			make -C ./libft/
			${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

bonus:		$(OBJS_B)
			make -C ./libft/
			${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS_B} ./libft/libft.a -o ${NAME}


all: 		$(NAME)

clean:
			$(RM) $(OBJS) $(DEP) $(OBJS_B) $(DEP_B)
			make clean -C libft/

fclean: 	clean
			$(RM) $(NAME)
			make fclean -C libft/

re: 		fclean all

-include $(DEP)
-include $(DEP_B)