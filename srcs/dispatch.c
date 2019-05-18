/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:14:48 by anjansse          #+#    #+#             */
/*   Updated: 2019/05/17 21:29:31 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			*init_id(int *array, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}

int					dispatcher(t_graph *graph, t_info *info)
{
	int			c;
	int			ant_index;
	int			nb_for_path[graph->count];

	//c = 0;
	ant_index = 0;
	init_id(nb_for_path, graph->count);
	ft_printf("NUMBER OF ANTS = %d\n", info->nb_ants);
	while (ant_index < info->nb_ants)
	{
		c = 0;
		while (c < graph->count)
		{
			//ft_printf("C = %d\n", c);
			if ((nb_for_path[c] + ant_index) <= graph->nb_room_in_paths[c])
			{
				printf("INDEX = %d\n", ant_index);
				ant_index++;
			}
			c++;
		}
	}
	return (1);
}
