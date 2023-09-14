/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:24:56 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/10 18:05:10 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file(char *file)
{
	int		fd;
	char	*dot;

	dot = ft_strchr(file, '.');
	if (!dot)
		file_error();
	if (ft_strcmp(dot, ".ber") != 0)
		file_error();
	fd = open(file, O_RDONLY);
	if (fd == -1)
		write_get_file_error(strerror(errno), file);
	return (fd);
}
