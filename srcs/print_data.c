/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 08:20:23 by Alex              #+#    #+#             */
/*   Updated: 2018/12/11 07:40:57 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		print_path(t_graph *graph, t_infos *info)
{
	size_t		i;
	int			j;

	i = 0;
	while (i <= info->nb_ants)
	{
		j = 0;
		while (graph->adj_list[j] != NULL)
		{
			printf("L%zu-%s", i + 1, graph->adj_list[j]->vertex);
			if (graph->adj_list[j + 1] != NULL)
				printf("\n");
			j++;
		}
		printf(" ");
		i++;
	}
}

void		print_queue(t_queue *queue)
{
	if (is_empty_queue(queue))
		printf("Queue is empty\n");
	else
	{
		while (queue->rear != NULL)
		{
			printf("%s  ", queue->rear->content);
			queue->rear = queue->rear->next;
		}
	}
}

void		print_hash()
{
	int			i;

	i = 0;
	while (i < 25)
	{
		if (hash_array[i] != NULL)
			printf(" (%d,%s)",hash_array[i]->key,hash_array[i]->data);
		else
			printf(" ~~ ");
		i++;
	}
	printf("\n");
}

void		print_infos(t_infos *info)
{
	printf("room start = %s\n", info->room_start);
	printf("room end = %s\n", info->room_end);
	printf("number of ants = %zu\n", info->nb_ants);
}

void		print_graph(t_graph *graph)
{
	int		v;
	t_adj	*tmp;

	v = 0;
	while (v < graph->nb_vertices)
	{
		tmp = graph->adj_list[v];
		printf("Adjacency list of vertex %s\n", hash_array[v]->data);
		while (tmp)
		{
			printf("%s -> ", tmp->vertex);
			tmp = tmp->next;
		}
		printf("\n");
		v++;
	}
}

void				print_list(t_list *lst)
{
	t_nodes *node;

	node = lst->head;
	while (node)
	{
		printf("line = %s\n", node->data);
		node = node->next;
	}
}
