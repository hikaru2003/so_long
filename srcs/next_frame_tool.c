/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame_tool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:03:00 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/10 19:03:08 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	serch_all(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->map = data->head.next;
	while (data->map != &data->head)
	{
		x = 0;
		while (data->map->row[x] != '\0')
		{
			if (data->map->row[x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				return ;
			}
			x++;
		}
		y++;
		data->map = data->map->next;
	}
}

void	move_to_player_y(t_data *data)
{
	int	y;

	y = 0;
	data->map = data->head.next;
	while (y < data->player_y)
	{
		data->map = data->map->next;
		y++;
	}
}

void	current_pos_img(t_data *data)
{
	if (data->exit_flag == 1)
	{
		data->map->row[data->player_x] = 'E';
		data->exit_flag = 0;
	}
	else
		data->map->row[data->player_x] = '0';
}

void	check_game_complete(t_data *data, int status)
{
	if (data->collected == data->c_num)
		ft_destroy(data);
	else
	{
		data->map->row[data->player_x] = '0';
		if (status == UP)
			data->map->prev->row[data->player_x] = 'P';
		if (status == DOWN)
			data->map->next->row[data->player_x] = 'P';
		if (status == LEFT)
			data->map->row[data->player_x - 1] = 'P';
		if (status == RIGHT)
			data->map->row[data->player_x + 1] = 'P';
		data->exit_flag = 1;
	}
}
