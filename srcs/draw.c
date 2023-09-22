/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:34:23 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/22 21:29:01 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_player(t_data *data, int x, int y)
{
	if (data->player.direction == FRONT)
		mlx_put_image_to_window(data->mlx, data->win,
			data->player_front_img, x * data->xpm_width, y * data->xpm_height);
	if (data->player.direction == BACK)
		mlx_put_image_to_window(data->mlx, data->win,
			data->player_back_img, x * data->xpm_width, y * data->xpm_height);
	if (data->player.direction == RIGHT)
		mlx_put_image_to_window(data->mlx, data->win,
			data->player_right_img, x * data->xpm_width, y * data->xpm_height);
	if (data->player.direction == LEFT)
		mlx_put_image_to_window(data->mlx, data->win,
			data->player_left_img, x * data->xpm_width, y * data->xpm_height);
}

static void	draw_one_image(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall_img,
			x * data->xpm_width, y * data->xpm_height);
	else if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->space_img,
			x * data->xpm_width, y * data->xpm_height);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->collect_img,
			x * data->xpm_width, y * data->xpm_height);
	else if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit_img,
			x * data->xpm_width, y * data->xpm_height);
	else if (data->map[y][x] == 'P')
		draw_player(data, x, y);
}

int	draw_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			draw_one_image(data, x, y);
			x++;
		}
		y++;
	}
	if (data->exit_flag == true)
		ft_destroy(data);
	return (0);
}
