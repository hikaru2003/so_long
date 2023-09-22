/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:24:56 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/22 13:00:37 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_size(int fd, t_data *data)
{
	char	*line;
	int		line_len;

	line_len = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line && data->map_height == 0)
			print_error("map is empty");
		if (!line)
			break ;
		if (ft_strchr(line, '\n'))
			line[ft_strchr(line, '\n') - line] = '\0';
		line_len = ft_strlen(line);
		if (data->map_width == 0)
			data->map_width = line_len;
		else if (data->map_width != line_len)
			print_error("map width incorrect");
		free(line);
		data->map_height++;
	}
}

void	check_file(char *filename, t_data *data)
{
	int		fd;
	char	*dot;

	dot = ft_strchr(filename, '.');
	if (!dot)
		print_error("filename incorrect");
	if (ft_strcmp(dot, ".ber") != 0)
		print_error("filename incorrect");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error(strerror(errno));
	check_map_size(fd, data);
	close(fd);
}
