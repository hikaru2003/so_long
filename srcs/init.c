/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:33:08 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/22 22:02:13 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_data *data)
{
	data->space_img = mlx_xpm_file_to_image(data->mlx,
			"image/field.xpm", &(data->xpm_width), &(data->xpm_height));
	data->wall_img = mlx_xpm_file_to_image(data->mlx,
			"image/stone.xpm", &(data->xpm_width), &(data->xpm_height));
	data->collect_img = mlx_xpm_file_to_image(data->mlx,
			"image/pikatyu.xpm", &(data->xpm_width), &(data->xpm_height));
	data->exit_img = mlx_xpm_file_to_image(data->mlx,
			"image/myuu2.xpm", &(data->xpm_width), &(data->xpm_height));
	data->player_front_img = mlx_xpm_file_to_image(data->mlx,
			"image/player_front.xpm", &(data->xpm_width), &(data->xpm_height));
	data->player_back_img = mlx_xpm_file_to_image(data->mlx,
			"image/player_back.xpm", &(data->xpm_width), &(data->xpm_height));
	data->player_right_img = mlx_xpm_file_to_image(data->mlx,
			"image/player_right.xpm", &(data->xpm_width), &(data->xpm_height));
	data->player_left_img = mlx_xpm_file_to_image(data->mlx,
			"image/player_left.xpm", &(data->xpm_width), &(data->xpm_height));
	if (!data->space_img || !data->wall_img || !data->collect_img
		|| !data->exit_img || !data->player_front_img || !data->player_back_img
		|| !data->player_right_img || !data->player_left_img)
		print_error(strerror(errno));
}

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		print_error(strerror(errno));
	data->map_width = 0;
	data->map_height = 0;
	data->xpm_height = 0;
	data->xpm_width = 0;
	data->player.x = 0;
	data->player.y = 0;
	data->player.direction = FRONT;
	data->collect_elements = 0;
	data->collected = 0;
	data->exit.x = 0;
	data->exit.y = 0;
	data->exit.direction = 0;
	data->exit_flag = false;
	data->step = 0;
	return (data);
}
