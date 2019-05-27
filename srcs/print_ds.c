/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 01:23:01 by ale-goff          #+#    #+#             */
/*   Updated: 2019/05/27 01:26:27 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		print_info(t_info *info)
{
	ft_printf("Number of ants-> %zu\n", info->nb_ants);
	ft_printf("Room start -> %s\n", info->room_start);
	ft_printf("Room end -> %s\n", info->room_end);
	ft_printf("Number of V -> %zu\n", info->nb_vertices);
}

void		print_matrix(char **matrix, t_info *info)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < info->nb_vertices)
	{
		j = 0;
		while (j < info->nb_vertices)
		{
			ft_printf("%d ", matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void		print_hash(void)
{
	int			i;

	i = 0;
	while (i < 25)
	{
		if (hash_array[i] != NULL)
			ft_printf(" (%d,%s)", hash_array[i]->key, hash_array[i]->data);
		else
			ft_printf(" ~~ ");
		i++;
	}
	ft_printf("\n");
}

void		print_graph(t_graph *graph)
{
	int		v;
	t_adj	*tmp;

	v = -1;
	while (++v < graph->nb_vertices)
	{
		tmp = graph->adj_list[v];
		while (tmp)
		{
			graph->nb_ways[v][1]++;
			tmp = tmp->next;
		}
	}
	tmp = NULL;
	v = -1;
	while (++v < graph->nb_vertices)
	{
		tmp = graph->adj_list[v];
		ft_printf("Adjacency list of vertex %s\n", hash_array[v]->data);
		while (tmp)
		{
			ft_printf("%s -> ", tmp->vertex);
			tmp = tmp->next;
		}
	}
}
