/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:41:42 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/22 21:29:38 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	next_frame(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		// data_free(data);
		exit(0);
	}
	if (keycode == 13 || keycode == 126)
		go_up(data);
	if (keycode == 1 || keycode == 125)
		go_down(data);
	if (keycode == 0 || keycode == 123)
		go_left(data);
	if (keycode == 2 || keycode == 124)
		go_right(data);
	return (0);
}

void	go_up(t_data *data)
{
	if (data->map[data->player.y][data->player.x] != 'P')
		search_player_pos(data);
	if (data->map[data->player.y - 1][data->player.x] != '1')
	{
		if (data->map[data->player.y - 1][data->player.x] == 'C')
			data->collected++;
		if (data->map[data->player.y - 1][data->player.x] == 'E'
			&& data->collected == data->collect_elements)
			data->exit_flag = true;
		data->map[data->player.y][data->player.x] = '0';
		if (data->player.x == data->exit.x && data->player.y == data->exit.y)
			data->map[data->player.y][data->player.x] = 'E';
		data->map[data->player.y - 1][data->player.x] = 'P';
		data->player.y -= 1;
		data->step++;
		ft_printf("steps : %d\n", data->step);
	}
	data->player.direction = BACK;
}

void	go_down(t_data *data)
{
	if (data->map[data->player.y][data->player.x] != 'P')
		search_player_pos(data);
	if (data->map[data->player.y + 1][data->player.x] != '1')
	{
		if (data->map[data->player.y + 1][data->player.x] == 'C')
			data->collected++;
		if (data->map[data->player.y + 1][data->player.x] == 'E'
			&& data->collected == data->collect_elements)
			data->exit_flag = true;
		data->map[data->player.y][data->player.x] = '0';
		if (data->player.x == data->exit.x && data->player.y == data->exit.y)
			data->map[data->player.y][data->player.x] = 'E';
		data->map[data->player.y + 1][data->player.x] = 'P';
		data->player.y += 1;
		data->step++;
		ft_printf("steps : %d\n", data->step);
	}
	data->player.direction = FRONT;
}

void	go_left(t_data *data)
{
	if (data->map[data->player.y][data->player.x] != 'P')
		search_player_pos(data);
	if (data->map[data->player.y][data->player.x - 1] != '1')
	{
		if (data->map[data->player.y][data->player.x - 1] == 'C')
			data->collected++;
		if (data->map[data->player.y][data->player.x - 1] == 'E'
			&& data->collected == data->collect_elements)
			data->exit_flag = true;
		data->map[data->player.y][data->player.x] = '0';
		if (data->player.x == data->exit.x && data->player.y == data->exit.y)
			data->map[data->player.y][data->player.x] = 'E';
		data->map[data->player.y][data->player.x - 1] = 'P';
		data->player.x -= 1;
		data->step++;
		ft_printf("steps : %d\n", data->step);
	}
	data->player.direction = LEFT;
}

void	go_right(t_data *data)
{
	if (data->map[data->player.y][data->player.x] != 'P')
		search_player_pos(data);
	if (data->map[data->player.y][data->player.x + 1] != '1')
	{
		if (data->map[data->player.y][data->player.x + 1] == 'C')
			data->collected++;
		if (data->map[data->player.y][data->player.x + 1] == 'E'
			&& data->collected == data->collect_elements)
			data->exit_flag = true;
		data->map[data->player.y][data->player.x] = '0';
		if (data->player.x == data->exit.x && data->player.y == data->exit.y)
			data->map[data->player.y][data->player.x] = 'E';
		data->map[data->player.y][data->player.x + 1] = 'P';
		data->player.x += 1;
		data->step++;
		ft_printf("steps : %d\n", data->step);
	}
	data->player.direction = RIGHT;
}
