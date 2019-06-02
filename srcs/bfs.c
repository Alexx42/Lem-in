/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:37:55 by anjansse          #+#    #+#             */
/*   Updated: 2019/06/02 14:39:17 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			init_bfs(t_graph **graph, t_queue *queue, t_info *info)
{
	size_t		i;

	i = -1;
	while (++i < info->nb_vertices)
		(*graph)->visited[i] = 0;
	enqueue(queue, info->room_start, NULL);
	(*graph)->visited[search_item(info->room_start)] = 1;
}

void			bfs_help(t_graph **graph, t_val *current_vertex, t_info *info)
{
	uint32_t	v;
	t_adj		*tmp2;
	t_val		*tmpcur;

	v = -1;
	while (++v < info->nb_vertices)
	{
		tmp2 = (*graph)->adj_list[v];
		while (tmp2)
		{
			tmpcur = get_vertex(tmpcur, current_vertex, info, tmp2);
			current_vertex = tmpcur;
			tmp2 = tmp2->next;
		}
	}
	add_path(graph, current_vertex);
}

int				bfs(t_graph **graph, t_queue *queue, t_info *info)
{
	t_val		*current_vertex;
	t_adj		*tmp;

	init_bfs(graph, queue, info);
	while (!is_empty_queue(queue))
	{
		current_vertex = dequeue(queue);
		tmp = (*graph)->adj_list[search_item(current_vertex->content)];
		while (tmp)
		{
			if (!(*graph)->visited[search_item(tmp->vertex)] && !tmp->flag)
			{
				if (!ft_strcmp(info->room_end, tmp->vertex))
				{
					enqueue(queue, tmp->vertex, current_vertex);
					bfs_help(graph, queue->rear, info);
					return (1);
				}
				enqueue(queue, tmp->vertex, current_vertex);
				(*graph)->visited[search_item(tmp->vertex)] = 1;
			}
			tmp = tmp->next;
		}
	}
	return (0);
}
