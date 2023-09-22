/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame_tool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:03:00 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/22 17:37:48 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_player_pos(t_data *data)
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
			if (data->map[y][x] == 'P')
			{
				data->player.x = x;
				data->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	print_error("player is not found.");
}
