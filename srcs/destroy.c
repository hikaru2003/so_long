/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:28:15 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/22 22:01:55 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	// map_free(data);
	// data_free(data);
	exit(0);
}
