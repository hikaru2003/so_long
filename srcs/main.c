/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:33:39 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/22 22:10:54 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		print_error("invalid argument.");
	data = init_data();
	check_file(argv[1], data);
	printf("check file\n");
	create_map(argv[1], data);
	printf("create map\n");
	check_playable(data);
	printf("check playable\n");
	data->mlx = mlx_init();
	init_img(data);
	// printf("map_width: %d, map_height: %d\n", data->map_width * 32, data->map_height * 32);
	data->win = mlx_new_window(data->mlx, data->map_width * 32,
			data->map_height * 32, "so_long");
	printf("mlx new window\n");
	mlx_hook(data->win, 2, 1, next_frame, data);
	mlx_hook(data->win, 17, 1, ft_destroy, data);
	mlx_loop_hook(data->mlx, draw_map, data);
	mlx_loop(data->mlx);
	return (0);
}

__attribute__((destructor))
static void	destructor(void){
	system("leaks -q so_long");
}
