/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:14:48 by anjansse          #+#    #+#             */
/*   Updated: 2019/05/25 15:21:30 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "../includes/lem_in.h"
#include "../libft/libft.h"

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
static void				print_ant_path(int ant, char *room)
{
		ft_putchar('L');
		ft_putnbr(ant);
		ft_putchar('-');
		ft_putstr(room);
		ft_putchar(' ');
}
/*
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
*/
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
	while (begin < end)
	{
		if (n[begin] == n[begin + 1] || n[begin] == n[end])
			return (1);
		begin++;
	}
	return (0);
}

int					send_ants(t_info *info, t_val **tmp, t_graph *graph, int ant, int *ant_path, int index)
{
	int i = 0;

	if (ant < info->nb_ants)
	{
		tmp[ant] = graph->path[ant_path[index]];
		//ft_printf("1.L%d-%s ", ant + 1, tmp[ant]->content);
		print_ant_path(ant + 1, tmp[ant]->content);
		if (tmp[ant])
			tmp[ant] = tmp[ant]->parent;
	}
	if (graph->verif == 0)
	{
		while (i < graph->limit)
		{
			if (tmp[i])
			{
				print_ant_path(i + 1, tmp[i]->content);
				//ft_printf("2.L%d-%s ", i + 1, tmp[i]->content);
				tmp[i] = tmp[i]->parent;
			}
			i++;
		}
		graph->verif = 1;
		return (1);
	}
	return (0);
}

void				send_it(int *ant_path, t_graph *graph, t_info *info)
{
	int i;
	int ant = 0;
	int ant_index = info->nb_ants;
	t_val **tmp;

	i = -1;
	tmp = (t_val **)malloc(sizeof(t_val *) * (info->nb_ants + 1));
	while (++i < graph->count)
		reverse_path(&graph->path[i]);
	while (ant_index > 0)
	{
		i = 0;
		graph->verif = 0;
		graph->limit = ant;
		while ((ant_index - i > 0) && (!in_previous(ant_path, ant_index, ant_index - i) || i == 0))
		{
			send_ants(info, tmp, graph, ant, ant_path, ant_index - i);
			ant++;
			i++;
		}
		ft_putchar('\n');
		ant_index = ant_index - i;
		if (ant == info->nb_ants)
		{
			while (tmp[info->nb_ants - 1] && ft_strcmp(tmp[info->nb_ants - 1]->content, info->room_end))
			{
				graph->limit = ant;
				graph->verif = 0;
				send_ants(info, tmp, graph, info->nb_ants, ant_path, ant_index - i);
				graph->verif = 0;
				ft_putchar('\n');
			}
			send_ants(info, tmp, graph, info->nb_ants, ant_path, ant_index - i);
		}
	}
	free(tmp);
}

int					dispatcher(t_graph *graph, t_info *info)
{
	int			c;
	int			ant_index;
	int			nb_for_path[graph->count];
	int         *ant_path;

	ant_index = 0;
	init_id(nb_for_path, graph->count);
	ant_path = (int *)malloc(sizeof(int) * (info->nb_ants + 1));
	//ft_printf("Ants: %d\n\n", info->nb_ants);
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
	graph->verif = 0;
	send_it(ant_path, graph, info);
	free(ant_path);
	return (1);
}
