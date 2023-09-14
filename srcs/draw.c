/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:34:23 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/10 19:34:40 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_data *data, t_map_index *index)
{
	if (data->player_direction == FRONT)
		mlx_put_image_to_window(data->mlx, data->win,
			data->player_front_img, index->x, index->y);
	if (data->player_direction == BACK)
		mlx_put_image_to_window(data->mlx, data->win,
			data->player_back_img, index->x, index->y);
	if (data->player_direction == RIGHT)
		mlx_put_image_to_window(data->mlx, data->win,
			data->player_right_img, index->x, index->y);
	if (data->player_direction == LEFT)
		mlx_put_image_to_window(data->mlx, data->win,
			data->player_left_img, index->x, index->y);
}

void	draw_one_image(t_data *data, t_map_index *index)
{
	if (data->map->row[index->width] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall_img,
			index->x, index->y);
	else if (data->map->row[index->width] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->space_img,
			index->x, index->y);
	else if (data->map->row[index->width] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->collect_img,
			index->x, index->y);
	else if (data->map->row[index->width] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit_img,
			index->x, index->y);
	else if (data->map->row[index->width] == 'P')
		draw_player(data, index);
}

int	draw_map(t_data *data)
{
	t_map_index	*index;

	index = (t_map_index *)malloc(sizeof(t_map_index));
	if (!index)
		print_error(data);
	index_init(index);
	data->map = data->head.next;
	while (index->height < data->height)
	{
		index->width = 0;
		index->x = 0;
		while (index->width < data->width)
		{
			draw_one_image(data, index);
			index->x += data->xpm_width;
			index->width++;
		}
		index->height++;
		index->y += data->xpm_height;
		data->map = data->map->next;
	}
	free(index);
	return (0);
}
