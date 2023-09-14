/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:23:23 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/14 20:24:20 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	array_free(t_data *data)
{
	int	y;

	y = 0;
	if (!data->array)
		return (0);
	while (y <= data->height)
	{
		free(data->array[y]);
		y++;
	}
	free(data->array);
	return (0);
}

int	map_status_free(t_map_status **map, t_data *data)
{
	int	y;

	y = 0;
	while (y < data->height)
	{
		free(map[y]);
		y++;
	}
	free(map);
	return (0);
}

int	map_free(t_data *data)
{
	t_map	*tmp;

	tmp = data->head.next;
	data->map = data->head.next;
	while (tmp != &data->head)
	{
		tmp = data->map->next;
		free(data->map->row);
		free(data->map);
		data->map = tmp;
	}
	return (0);
}

int	data_free(t_data *data)
{
	if (!data)
		free(data);
	return (0);
}
