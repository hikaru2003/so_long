/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:53:34 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/22 21:30:38 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_is_visited(t_data *test, t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		return ;
	if (test->map[y][x] == VISITED)
		return ;
	test->map[y][x] = VISITED;
	check_is_visited(test, data, x, y - 1);
	check_is_visited(test, data, x, y + 1);
	check_is_visited(test, data, x - 1, y);
	check_is_visited(test, data, x + 1, y);
}

static void	check_is_clearable_map(t_data *test, t_data *data)
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
			if ((data->map[y][x] == 'C' || data->map[y][x] == 'E')
				&& test->map[y][x] == NOT_VISITED)
				print_error("map is not clearable.");
			x++;
		}
		y++;
	}
}

void	check_playable(t_data *data)
{
	int		i;
	t_data	*test;

	i = 0;
	test = (t_data *)malloc(sizeof(t_data));
	if (!test)
		print_error(strerror(errno));
	test->map = (char **)malloc(sizeof(char *) * (data->map_height + 1));
	while (i < data->map_height)
	{
		test->map[i] = (char *)malloc(sizeof(char) * (data->map_width + 1));
		if (!test->map[i])
			print_error(strerror(errno));
		test->map[i] = ft_memset(test->map[i], NOT_VISITED, data->map_width);
		test->map[i][data->map_width] = '\0';
		i++;
	}
	test->map_height = data->map_height;
	test->collected = 0;
	test->exit_flag = false;
	check_is_visited(test, data, data->player.x, data->player.y);
	check_is_clearable_map(test, data);
	free_map(test);
	free(test);
}
