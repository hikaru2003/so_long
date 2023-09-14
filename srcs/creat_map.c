/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:55:37 by hmorisak          #+#    #+#             */
/*   Updated: 2023/05/04 20:48:03 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	insert(t_map *head, t_map *new)
{
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
	new->next = head;
}

t_map	creat_map(int fd, t_data *data)
{
	char	*line;
	t_map	*map;

	data->height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (data->height == 0 && !line)
			print_error(data);
		if (!line)
			break ;
		if (ft_strlen(line) > 1000)
			print_error(data);
		map = (t_map *)malloc(sizeof(t_map));
		if (!map)
			return (data->head);
		map->row = line;
		insert(&data->head, map);
		data->height++;
		if (data->height > 500)
			print_error(data);
	}
	data->width = ft_strlen(data->head.next->row) - 1;
	return (data->head);
}
