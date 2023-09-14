/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:34:45 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/11 20:05:18 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	top_bottom_check(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->width)
	{
		if (data->map->row[x] != '1')
			print_error(data);
		x++;
	}
	if (data->map->row[x] != '\n' && data->map->row[x] != '\0')
		print_error(data);
}

void	middle_check(t_data *data, int y)
{
	int	x;

	x = 0;
	while (x < data->width)
	{
		if (!ft_strchr("01CEP", data->map->row[x]))
			print_error(data);
		if ((x == 0 || x == data->width - 1) && data->map->row[x] != '1')
			print_error(data);
		if (data->map->row[x] == 'P')
		{
			if (data->player_x != 0)
				print_error(data);
			data->player_x = x;
			data->player_y = y;
		}
		if (data->map->row[x] == 'C')
			data->c_num++;
		if (data->map->row[x] == 'E')
			data->e_num++;
		x++;
	}
	if (data->map->row[x] != '\n' && data->map->row[x] != '\0')
		print_error(data);
}

void	check_map_elements(t_data *data)
{
	if (data->c_num < 1)
		print_error(data);
	if (data->e_num != 1)
		print_error(data);
}

int	check_map(t_data *data)
{
	int	y;

	y = 0;
	data->map = data->head.next;
	while (y < data->height)
	{
		if (y == 0 || y == data->height - 1)
			top_bottom_check(data);
		else
			middle_check(data, y);
		y++;
		data->map = data->map->next;
	}
	check_map_elements(data);
	printf("check map element\n");
	printf("%d\n", data->width);
	check_goal(data);
	printf("check goal");
	return (0);
}
