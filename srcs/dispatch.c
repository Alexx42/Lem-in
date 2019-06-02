/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:14:48 by anjansse          #+#    #+#             */
/*   Updated: 2019/06/01 20:56:23 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			update_status(t_val **tmp, t_graph *graph, int index)
{
	int i;

	i = -1;
	if (graph->ant[0] < graph->ant[1])
	{
		tmp[graph->ant[0]] = graph->path[index];
		print_ant_path(graph->ant[0] + 1, tmp[graph->ant[0]]->content);
		if (tmp[graph->ant[0]])
			tmp[graph->ant[0]] = tmp[graph->ant[0]]->parent;
	}
	if (graph->verif == 0)
	{
		while (++i < graph->limit)
		{
			if (tmp[i])
			{
				print_ant_path(i + 1, tmp[i]->content);
				tmp[i] = tmp[i]->parent;
			}
		}
		graph->verif = 1;
		return (1);
	}
	return (0);
}

static void			other_send_ants(t_graph *graph, t_info *info,
					int i, t_val **tmp)
{
	ft_putchar('\n');
	graph->ant[2] = graph->ant[2] - i;
	if (graph->ant[0] == graph->ant[1])
	{
		while (tmp[graph->ant[1] - 1] &&
		ft_strcmp(tmp[graph->ant[1] - 1]->content, info->room_end))
		{
			graph->limit = graph->ant[0];
			graph->verif = 0;
			update_status(tmp, graph, graph->ant_path[graph->ant[2]]);
			graph->verif = 0;
			ft_putchar('\n');
		}
		update_status(tmp, graph, graph->ant_path[graph->ant[2]]);
	}
}

void				send_ants(t_graph *graph, t_info *info)
{
	int			i;
	t_val		**tmp;

	i = -1;
	graph->ant[0] = 0;
	graph->ant[1] = info->nb_ants;
	graph->ant[2] = info->nb_ants;
	tmp = (t_val **)malloc(sizeof(t_val *) * (graph->ant[1] + 1));
	while (++i < graph->count)
		reverse_path(&graph->path[i]);
	while (graph->ant[2] > 0)
	{
		i = 0;
		graph->verif = 0;
		graph->limit = graph->ant[0];
		while ((graph->ant[2] - i > 0) && (!in_previous(graph->ant_path,\
						graph->ant[2], graph->ant[2] - i) || i == 0))
		{
			update_status(tmp, graph, graph->ant_path[graph->ant[2] - i]);
			graph->ant[0]++;
			i++;
		}
		other_send_ants(graph, info, i, tmp);
	}
	free(tmp);
}

static int			other_dispatch(t_graph *graph, t_info *info,
					int ant_index, int *nb_for_path)
{
	while (info->c < graph->count && ant_index < info->nb_ants)
	{
		if (info->c + 1 < graph->count && (nb_for_path[info->c] + \
					graph->nrip[info->c]) <= graph->nrip[info->c + 1])
		{
			nb_for_path[info->c]++;
			ant_index++;
			graph->ant_path[ant_index] = info->c;
		}
		else if (info->c + 1 < graph->count && graph->nrip[info->c + 1]\
				&& (nb_for_path[info->c] + graph->nrip[info->c]) >\
				graph->nrip[info->c + 1] && nb_for_path[info->c + 1] == 0)
			info->c++;
		else
		{
			nb_for_path[info->c]++;
			ant_index++;
			graph->ant_path[ant_index] = info->c;
			info->c++;
		}
	}
	return (ant_index);
}

int					dispatcher(t_graph *graph, t_info *info)
{
	int			ant_index;
	int			nb_for_path[graph->count];

	ant_index = 0;
	init_id(nb_for_path, graph->count);
	graph->ant_path = (int *)malloc(sizeof(int) * (info->nb_ants + 1));
	while (ant_index < info->nb_ants)
	{
		info->c = 0;
		ant_index = other_dispatch(graph, info, ant_index, nb_for_path);
	}
	graph->verif = 0;
	send_ants(graph, info);
	ft_putchar('\n');
	free(graph->ant_path);
	return (1);
}
