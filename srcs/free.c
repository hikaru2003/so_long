/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:23:23 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/22 19:04:25 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (!data->map)
		return ;
	while (i <= data->map_height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

int	data_free(t_data *data)
{
	if (!data)
		free(data);
	return (0);
}
