/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 06:05:47 by Alex              #+#    #+#             */
/*   Updated: 2018/12/11 07:37:50 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int			bfs(t_graph *graph, t_queue *queue, t_infos *info)
{
	char	*current_vertex;
	char	*adj_vertex;
	t_adj	*tmp;

	graph->visited[search_item(info->room_start)] = 1;
	enqueue(queue, info->room_start);
	while (!is_empty_queue(queue))
	{
		current_vertex = dequeue(queue);
		tmp = graph->adj_list[search_item(current_vertex)];
		while (tmp)
		{
			adj_vertex = tmp->vertex;
			if (graph->visited[search_item(adj_vertex)] == 0)
			{
				graph->visited[search_item(adj_vertex)] = 1;
				enqueue(queue, adj_vertex);
			}
			if (!ft_strcmp(adj_vertex, info->room_end)){
				printf("arrived\n");
			}
			tmp = tmp->next;
		}
	}
	return (1);
}

int			general_algorithm(t_graph *graph, t_infos *info)
{
	t_queue			*queue;

	queue = create_queue();
	bfs(graph, queue, info);
	print_path(graph, info);
	return (0);
}