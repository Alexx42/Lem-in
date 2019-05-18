/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:14:48 by anjansse          #+#    #+#             */
/*   Updated: 2019/05/18 14:20:23 by ale-goff         ###   ########.fr       */
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

	ant_index = 0;
	init_id(nb_for_path, graph->count);
	ft_printf("NUMBER OF ANTS = %d\n", info->nb_ants);
	while (ant_index < info->nb_ants)
	{
		c = 0;
		while (c < graph->count)
		{
			ft_printf("value of id is %d\n", nb_for_path[c]);
			if (c + 1 < graph->count && (nb_for_path[c] + graph->nrip[c]) <= graph->nrip[c + 1])
			{
				nb_for_path[c]++;
				ant_index++;
			}
			else if (c + 1 < graph->count && graph->nrip[c + 1] && (nb_for_path[c] + graph->nrip[c]) > graph->nrip[c + 1])
			{
				c++;
			}
			else
			{
				ft_putstr("coucou\n");
				ant_index++;
				c++;
			}
			printf("ANT %d GOES BY PATH %d\n", ant_index, c);
		}
		//ft_putstr("iuqeh\n");
	}
	return (1);
}
