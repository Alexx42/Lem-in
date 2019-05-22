/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:14:48 by anjansse          #+#    #+#             */
/*   Updated: 2019/05/21 17:27:56 by anjansse         ###   ########.fr       */
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
	t_val	*tmp;

	tmp = path;
	while (tmp)
	{
		ft_printf("ROOM IS %s\n", tmp->content);
		tmp = tmp->parent;
	}
	ft_putchar('\n');
}

void		reverse_path(t_val **path)
{
	t_val	*prev;
	t_val	*current;
	t_val	*next;

	prev = NULL;
	current = *path;
	next = NULL;
	while (current->parent != NULL)
	{
		next = current->parent;
		current->parent = prev;
		prev = current;
		current = next;
	}
	*path = prev;
}

static int			in_previous(int *n, int end, int begin)
{
	//ft_printf("BEING COMPARED: BEGIN %d\tEND %d\n", n[begin], n[end]);
	while (begin < end)
	{
		if (n[begin] == n[begin + 1] || n[begin] == n[end])
			return (1);
		begin++;
	}
	return (0);
}

void				send_ants(t_val **tmp, t_graph *graph, int ant, int *ant_path, int index)
{
	int i = 1;

	//tmp[ant] = malloc(sizeof(t_val));
	tmp[ant] = graph->path[ant_path[index]];
	//ft_printf("I -> %d\tANT -> %s\n", ant, tmp[ant]->content);
	//ft_printf("L%d-%s ", ant, tmp[ant]->content);
	//if (tmp[ant])
		//tmp[ant] = tmp[ant]->parent;
	while (i <= ant)
	{
		if (tmp[i])
		{
			ft_printf("L%d-%s ", i, tmp[i]->content);
			tmp[i] = tmp[i]->parent;
		}
		i++;
	}
	//ft_putchar('\n');
}

void				send_it(int *ant_path, t_graph *graph, t_info *info, t_val *head)
{
	(void)head;
	//(void)graph;
	(void)info;
	/*reverse_path(graph->path[1]);*/
	int i;
	int ant = 1;
	int ant_index = info->nb_ants;
	t_val **tmp;

	i = -1;
	tmp = (t_val **)malloc(sizeof(t_val *) * (info->nb_ants + 1));
	while (++i < graph->count)
		reverse_path(&graph->path[i]);
	//ft_printf("EIWFGIWRG %d\n", ant_path[ant_index - 2]);
	while (ant_index > 0)
	{
		i = 0;
		while ((ant_index - i > 0) && (!in_previous(ant_path, ant_index, ant_index - i) || i == 0))
		{
			//print_list(graph->path[ant_path[ant_index - i]]);
			send_ants(tmp, graph, ant, ant_path, ant_index - i);
			//ft_printf("L%d-%s ", ant, graph->path[ant_path[ant_index - i]]->content);
			ant++;
			i++;
		}
		ft_putstr("\n----------------------\n");
		ant_index = ant_index - i;
	}
	//print_list(reverse_path(graph->path[ant_path[ant_index]]));
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
