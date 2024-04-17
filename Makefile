NAME        =    push_swap

IDIR        =    push_swap.h

SRCS		=	action.c \
				check_arg.c \
				cout.c \
				ft_libft.c \
				libft_lst.c \
				libft_m_lst.c \
				math_tools.c \
				optmize_mvt.c \
				push_swap.c \
				sort_medium.c \
				sort_short.c \
				tools_lst.c \
				utils_check.c \
				ft_split.c \

OBJS		=	$(SRCS:.c=.o)
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
NORM		=	norminette *.h && norminette *.c 

all			:	$(NAME)

$(NAME)		:	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

n			:
	$(NORM)

clean		:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean		:	clean
	$(RM) $(NAME)

re			:	fclean all

.PHONY:		all clean fclean re bonus
