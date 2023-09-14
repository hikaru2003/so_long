NAME = so_long

SRCS	=	srcs/check_file.c			\
			srcs/check_goal.c			\
			srcs/check_map.c			\
			srcs/creat_map.c			\
			srcs/destroy.c				\
			srcs/draw.c					\
			srcs/error.c				\
			srcs/free.c					\
			srcs/ft_print_conv.c		\
			srcs/ft_printf.c			\
			srcs/ft_put.c				\
			srcs/ft_strchr.c			\
			srcs/ft_strcmp.c			\
			srcs/ft_strdup.c			\
			srcs/ft_strlen.c			\
			srcs/get_next_line_utils.c	\
			srcs/get_next_line.c		\
			srcs/init.c					\
			srcs/main.c					\
			srcs/next_frame_tool.c		\
			srcs/next_frame.c			\
			srcs/to_hexa.c				\


OBJS = $(SRCS:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I include

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJS) $(M_OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

bonus:	$(OBJS) $(B_OBJS)
	make WITH_BONUS=1

re: fclean all

.PHONY: all clean fclean bonus re