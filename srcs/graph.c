/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 01:22:39 by ale-goff          #+#    #+#             */
/*   Updated: 2019/06/02 15:05:19 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include "../includes/lem_in.h"

t_adj		*new_adj(char *val)
{
	t_adj			*adj;

	if ((adj = (t_adj*)malloc(sizeof(t_adj))) == NULL)
		return (NULL);
	adj->vertex = val;
	adj->flag = 0;
	adj->next = NULL;
	return (adj);
}

t_graph		*new_graph(int num_vertices)
{
	t_graph		*new_graph;
	int			i;

	if ((new_graph = (t_graph*)malloc(sizeof(t_graph))) == NULL)
		return (NULL);
	new_graph->nb_vertices = num_vertices;
	new_graph->count = 0;
	new_graph->nb_ways = (int **)malloc(sizeof(int*) * (num_vertices + 1));
	new_graph->adj_list = (t_adj **)malloc(sizeof(t_adj*) * (num_vertices));
	new_graph->path = NULL;
	new_graph->path = (t_val **)malloc(sizeof(t_val *) * num_vertices);
	i = 0;
	new_graph->visited = (int *)malloc(sizeof(int) * (num_vertices));
	while (i < num_vertices)
	{
		new_graph->adj_list[i] = NULL;
		new_graph->nb_ways[i] = (int *)malloc(sizeof(int) * 3);
		new_graph->path[i] = NULL;
		new_graph->nb_ways[i][0] = 0;
		new_graph->nb_ways[i][1] = 0;
		new_graph->nb_ways[i][2] = 0;
		i++;
	}
	new_graph->nb_ways[i] = NULL;
	return (new_graph);
}

void		add_edge(t_graph *graph, char *src, char *dst)
{
	t_adj			*new_node;

	if (src >= 0 && dst >= 0)
	{
		new_node = new_adj(dst);
		if ((search_item(src) < 0))
			send_error();
		new_node->next = graph->adj_list[search_item(src)];
		graph->adj_list[search_item(src)] = new_node;
		new_node = new_adj(src);
		new_node->next = graph->adj_list[search_item(dst)];
		graph->adj_list[search_item(dst)] = new_node;
	}
}
