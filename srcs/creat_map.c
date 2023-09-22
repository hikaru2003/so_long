/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:55:37 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/22 22:09:09 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_is_wall(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1')
			print_error("map is not surrounded by walls.");
		i++;
	}
}

void	check_duplicate_and_set(t_coordinate *pos, int x, int y, char *msg)
{
	if (pos->x != 0 && pos->y != 0)
		print_error(msg);
	pos->x = x;
	pos->y = y;
}

static void	check_elements(int y, t_data *data)
{
	int	i;

	i = 1;
	if (data->map[y][0] != '1' || data->map[y][data->map_width - 1] != '1')
		print_error("map is not surrounded by walls.");
	while (data->map[y][i])
	{
		if (!ft_strchr("01CEP", data->map[y][i]))
			print_error("map contains invalid characters.");
		if (data->map[y][i] == 'C')
			data->collect_elements++;
		if (data->map[y][i] == 'E')
			check_duplicate_and_set(&data->exit, i, y,
				"map contains multiple exits.");
		if (data->map[y][i] == 'P')
			check_duplicate_and_set(&data->player, i, y,
				"map contains multiple players.");
		i++;
	}
}

static void	set_map(int fd, t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	while (i < data->map_height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strchr(line, '\n'))
			line[ft_strchr(line, '\n') - line] = '\0';
		data->map[i] = ft_strdup(line);
		if (!data->map[i])
			print_error(strerror(errno));
		if (i == 0 || i == data->map_height - 1)
			check_is_wall(data->map[i]);
		else
			check_elements(i, data);
		free(line);
		i++;
	}
}

void	create_map(char *filename, t_data *data)
{
	int		fd;

	data->map = (char **)malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map)
		print_error(strerror(errno));
	fd = open(filename, O_RDONLY);
	set_map(fd, data);
	if (data->collect_elements == 0)
		print_error("map does not contain collectible elements.");
	if (data->exit.x == 0 && data->exit.y == 0)
		print_error("map does not contain exit.");
	if (data->player.x == 0 && data->player.y == 0)
		print_error("map does not contain starting position.");
	data->map[data->map_height] = NULL;
	close (fd);
}
