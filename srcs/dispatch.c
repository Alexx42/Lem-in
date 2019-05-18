/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:14:48 by anjansse          #+#    #+#             */
/*   Updated: 2019/05/18 00:37:48 by anjansse         ###   ########.fr       */
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
		ft_putstr("BREAK\n");
		c = 0;
		while (c < graph->count)
		{
			printf("ANT %d GOES BY PATH %d\n", ant_index + 1, c);
			if (graph->nrip[c + 1] && (nb_for_path[c] + graph->nrip[c]) < graph->nrip[c + 1])
			{
				nb_for_path[c]++;
				ant_index++;
			}
			else if (graph->nrip[c + 1] && (nb_for_path[c] + graph->nrip[c]) >= graph->nrip[c + 1])
			{
				nb_for_path[c]++;
				ant_index++;
				c++;
			}
			printf("C = %d\tMAX = %d\n", c, graph->count);
		}
	}
	return (1);
}