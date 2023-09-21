/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:33:39 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/20 18:50:30 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		file_error();
	check_file(argv[1]);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		file_error();
	data->mlx = mlx_init();
	data_init(data);
	data->head = creat_map(check_file(argv[1]), data);
	if (check_map(data) != 0)
		exit(1);
	data->win = mlx_new_window(data->mlx, data->width * 32,
			data->height * 32, "so_long");
	mlx_hook(data->win, 2, 1, next_frame, data);
	mlx_hook(data->win, 17, 1, ft_destroy, data);
	mlx_loop_hook(data->mlx, draw_map, data);
	mlx_loop(data->mlx);
	return (0);
}

// __attribute__((destructor))
// static void	destructor(void){
// 	system("leaks -q so_long");
// }
