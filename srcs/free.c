/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:35:49 by anjansse          #+#    #+#             */
/*   Updated: 2019/05/27 10:37:05 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_queue(t_queue *queue)
{
	t_val		*tmp;

	while (!is_empty_queue(queue))
	{
		tmp = dequeue(queue);
		free(tmp->content);
		free(tmp);
	}
	free(queue);
}

void			free_hash(void)
{
	int			i;

	i = 0;
	while (i < SIZE)
	{
		if (hash_array[i])
		{
			free(hash_array[i]->data);
			free(hash_array[i]);
		}
		i++;
	}
}

void			free_graph(t_graph *graph, t_info *info)
{
	size_t		i;
	t_adj		*tmp;
	t_adj		*next;

	i = -1;
	while (++i < info->nb_vertices)
	{
		free(graph->nb_ways[i]);
		tmp = graph->adj_list[i];
		while (graph->adj_list[i])
		{
			next = graph->adj_list[i]->next;
			free(graph->adj_list[i]->vertex);
			graph->adj_list[i] = next;
		}
		graph->adj_list[i] = tmp;
		free(graph->adj_list[i]);
		free(graph->path[i]);
	}
	free(graph->visited);
	free(graph->nrip);
	free(graph->path);
	free(graph->nb_ways);
	free(graph->adj_list);
	free(graph);
}

void			free_info(t_info *info)
{
	free(info->room_end);
	free(info->room_start);
	free(info);
}
