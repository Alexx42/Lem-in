/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:14:48 by anjansse          #+#    #+#             */
/*   Updated: 2019/05/20 16:35:03 by anjansse         ###   ########.fr       */
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

void				print_list(t_val *path)
{
	while (path->parent)
	{
		ft_printf("ROOM IS %s\n", path->content);
		path = path->parent;
	}
	ft_printf("ROOM IS %s\n", path->content);
}

t_val				*reverse_path(t_val *path)
{
	t_val	*prev;
	t_val	*current;
	t_val	*next;

	prev = NULL;
	current = path;
	next = NULL;
	while (current != NULL)
	{
		next = current->parent;
		current->parent = prev;
		prev = current;
		current = next;
	}
	path = prev;
	return (path);
}

void				send_it(int *ant_path, t_graph *graph, t_info *info, t_val *head)
{
	(void)head;
	/*reverse_path(graph->path[1]);*/
	int ant_index = info->nb_ants;
/*
	while (ant_index > 0)
	{
		while (ant_path[ant_index])
		{
			print_list(reverse_path(graph->path[ant_path[ant_index]]));
		}
	}
	*/
	print_list(reverse_path(graph->path[ant_path[ant_index]]));
}

int					dispatcher(t_graph *graph, t_info *info, t_val *head)
{
	int			c;
	int			ant_index;
	int			nb_for_path[graph->count];
	int			*ant_path;

	ant_index = 0;
	init_id(nb_for_path, graph->count);
	ant_path = (int *)malloc(sizeof(int) * (info->nb_ants + 1));
	ft_printf("NUMBER OF ANTS = %d\n", info->nb_ants);
	while (ant_index < info->nb_ants)
	{
		c = 0;
		while (c < graph->count && ant_index < info->nb_ants)
		{
			if (c + 1 < graph->count && (nb_for_path[c] + graph->nrip[c]) <= graph->nrip[c + 1])
			{
				//ft_printf("B%d.\n\n", i);
				//printf("L%d-%d\n", ant_index, c);
				nb_for_path[c]++;
				ant_index++;
				ant_path[ant_index] = c;
			}
			else if (c + 1 < graph->count && graph->nrip[c + 1] && (nb_for_path[c] + graph->nrip[c]) > graph->nrip[c + 1] && nb_for_path[c + 1] == 0)
			{
				c++;
			}
			else
			{
				nb_for_path[c]++;
				ant_index++;
				//printf("L%d-%d\n", ant_index, c);
				ant_path[ant_index] = c;
				c++;
			}
		}
	}
	send_it(ant_path, graph, info, head);
	return (1);
}
