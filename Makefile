NAME = so_long

SRCS	=	check_file.c			\
			check_goal.c			\
			check_map.c				\
			creat_map.c				\
			destroy.c				\
			draw.c					\
			error.c					\
			free.c					\
			ft_print_conv.c			\
			ft_printf.c				\
			ft_put.c				\
			get_next_line_utils.c	\
			get_next_line.c			\
			init.c					\
			main.c					\
			next_frame_tool.c		\
			next_frame.c			\
			to_hexa.c				\

INCLUDE_DIR = ./include
SRCDIR = ./srcs/
OBJDIR = ./obj/

MLX_DIR = ./mlx/

LIBFT_DIR = ./libft/
LIBFT_A = $(LIBFT_DIR)libft.a

OBJS = $(SRCS:%.c=$(OBJDIR)%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I include

MLX_FLAG = -lmlx -framework OpenGL -framework AppKit

all: $(LIBFT_A) $(OBJDIR) $(NAME)

$(NAME): $(MLX_DIR) $(LIBFT_A) $(OBJDIR) $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -Lmlx $(MLX_FLAG) -o $(NAME) $(LIBFT_A) $(OBJS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT_A):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(MLX_DIR)
	make fclean -C $(LIBFT_DIR)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
