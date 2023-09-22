/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:24:48 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/22 12:08:44 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	write_get_file_error(char *err_msg, char *file)
// {
// 	write(STDERR, "zsh: ", 5);
// 	write(STDERR, err_msg, ft_strlen(err_msg));
// 	write(STDERR, ": ", 2);
// 	write(STDERR, file, ft_strlen(file));
// 	write(STDERR, "\n", 1);
// 	exit(1);
// }

// void	file_error(void)
// {
// 	write(2, "error\n", 6);
// 	exit(1);
// }

// void	print_error(t_data *data)
// {
// 	write(2, "error\n", 6);
// 	map_free(data);
// 	data_free(data);
// 	exit(1);
// }

void	print_error(char *msg)
{
	ft_printf("Error: %s\n", msg);
	exit (1);
}
