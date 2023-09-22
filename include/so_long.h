/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:26:20 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/22 18:25:00 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include "../libft/libft.h"

# define KEY_ESC		65307

# define STDIN			0
# define STDOUT			1
# define STDERR			2

# define FRONT			0
# define UP				0
# define BACK			1
# define DOWN			1
# define RIGHT			2
# define LEFT			3

# define VISITED		49
# define NOT_VISITED	48

typedef struct s_coordinate
{
	int	x;
	int	y;
	int	direction;
}	t_coordinate;

typedef struct s_data
{
	char			**map;
	int				map_width;
	int				map_height;
	int				xpm_height;
	int				xpm_width;
	void			*mlx;
	void			*win;
	void			*space_img;
	void			*wall_img;
	void			*collect_img;
	void			*exit_img;
	void			*player_front_img;
	void			*player_back_img;
	void			*player_right_img;
	void			*player_left_img;
	t_coordinate	player;
	t_coordinate	exit;
	int				collect_elements;
	int				collected;
	bool			exit_flag;
	int				step;
}	t_data;

//check_file.c
void	check_file(char *filename, t_data *data);

//check_playable.c
void	check_playable(t_data *data);

//creat_map.c
void	create_map(char *filename, t_data *data);

//destroy.c
int		ft_destroy(t_data *data);

//draw.c
int		draw_map(t_data *data);

//error.c
void	print_error(char *msg);

//free.c
// int		array_free(t_data *data);
// int		map_status_free(t_map_status **map, t_data *data);
// int		map_free(t_data *data);
void	free_map(t_data *data);
int		data_free(t_data *data);

//printf
size_t	ft_strlen(const char *c);
int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putnbr(int n, int *len);
void	to_hexa(unsigned long long num, char *str, int *len);
void	print_conv(const char *format, va_list *args, int *len);
void	ft_putnbr_u(unsigned int n, int *len);

//gnl
char	*get_next_line(int fd);
char	*gnl_strjoin(char *line, char *buf);
char	*ft_free(char **str);

//init.c
void	init_img(t_data *data);
t_data	*init_data(void);

//next_frame_tool.c
void	search_player_pos(t_data *data);

//next_frame.c
int		next_frame(int keycode, t_data *data);
void	go_up(t_data *data);
void	go_down(t_data *data);
void	go_left(t_data *data);
void	go_right(t_data *data);

#endif
