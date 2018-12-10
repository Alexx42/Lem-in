/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 07:15:23 by Alex              #+#    #+#             */
/*   Updated: 2018/12/10 14:00:39 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_adj		*new_adj(char *val)
{
	t_adj			*adj;

	if ((adj = (t_adj*)malloc(sizeof(t_adj))) == NULL)
		return (NULL);
	adj->vertex = val;
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
	new_graph->adj_list = (t_adj **)malloc(sizeof(t_adj*) * (num_vertices + 3123));
	i = 0;
	while (i < num_vertices)
	{
		new_graph->adj_list[i] = NULL;
		i++;
	}
	return (new_graph);
}

void		add_edge(t_graph *graph, char *src, char *dst)
{
	t_adj			*new_node;

	if (src >= 0 && dst >= 0)
	{
		new_node = new_adj(dst);
		new_node->next = graph->adj_list[search_item(src)];
		graph->adj_list[search_item(src)] = new_node;

		new_node = new_adj(src);
		new_node->next = graph->adj_list[search_item(dst)];
		graph->adj_list[search_item(dst)] = new_node;
	}
}

