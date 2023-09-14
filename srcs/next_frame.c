/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:41:42 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/22 13:54:20 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	next_frame(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		map_free(data);
		data_free(data);
		exit(0);
	}
	if (keycode == 13 || keycode == 126)
		do_up(data);
	if (keycode == 1 || keycode == 125)
		do_down(data);
	if (keycode == 0 || keycode == 123)
		do_left(data);
	if (keycode == 2 || keycode == 124)
		do_right(data);
	return (0);
}

void	do_up(t_data *data)
{
	move_to_player_y(data);
	if (data->map->row[data->player_x] != 'P')
		serch_all(data);
	if (data->map->prev->row[data->player_x] != '1')
	{
		if (data->map->prev->row[data->player_x] == 'C')
			data->collected++;
		if (data->map->prev->row[data->player_x] == 'E')
			check_game_complete(data, UP);
		else
		{
			current_pos_img(data);
			data->map->prev->row[data->player_x] = 'P';
		}
		data->player_y -= 1;
		data->step++;
		ft_printf("steps : %d\n", data->step);
	}
	data->player_direction = BACK;
}

void	do_down(t_data *data)
{
	move_to_player_y(data);
	if (data->map->row[data->player_x] != 'P')
		serch_all(data);
	if (data->map->next->row[data->player_x] != '1')
	{
		if (data->map->next->row[data->player_x] == 'C')
			data->collected++;
		if (data->map->next->row[data->player_x] == 'E')
			check_game_complete(data, DOWN);
		else
		{
			current_pos_img(data);
			data->map->next->row[data->player_x] = 'P';
		}
		data->player_y += 1;
		data->step++;
		ft_printf("steps : %d\n", data->step);
	}
	data->player_direction = FRONT;
}

void	do_left(t_data *data)
{
	move_to_player_y(data);
	if (data->map->row[data->player_x] != 'P')
		serch_all(data);
	if (data->map->row[data->player_x - 1] != '1')
	{
		if (data->map->row[data->player_x - 1] == 'C')
			data->collected++;
		if (data->map->row[data->player_x - 1] == 'E')
			check_game_complete(data, LEFT);
		else
		{
			current_pos_img(data);
			data->map->row[data->player_x - 1] = 'P';
		}
		data->player_x -= 1;
		data->step++;
		ft_printf("steps : %d\n", data->step);
	}
	data->player_direction = LEFT;
}

void	do_right(t_data *data)
{
	move_to_player_y(data);
	if (data->map->row[data->player_x] != 'P')
		serch_all(data);
	if (data->map->row[data->player_x + 1] != '1')
	{
		if (data->map->row[data->player_x + 1] == 'C')
			data->collected++;
		if (data->map->row[data->player_x + 1] == 'E')
			check_game_complete(data, RIGHT);
		else
		{
			current_pos_img(data);
			data->map->row[data->player_x + 1] = 'P';
		}
		data->player_x += 1;
		data->step++;
		ft_printf("steps : %d\n", data->step);
	}
	data->player_direction = RIGHT;
}
