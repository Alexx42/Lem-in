/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:38:54 by anjansse          #+#    #+#             */
/*   Updated: 2019/05/27 10:52:41 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			add_path(t_graph **graph, t_val *current_vertex)
{
	(*graph)->path[(*graph)->count] = current_vertex;
	(*graph)->count++;
}

t_val			*get_vertex(t_val *tmpcur, t_val *current_vertex,
				t_info *info, t_adj *tmp2)
{
	tmpcur = current_vertex;
	while (current_vertex->parent)
	{
		if (current_vertex->parent)
			if (!ft_strcmp(tmp2->vertex, current_vertex->content))
				if (ft_strcmp(tmp2->vertex, info->room_end) || \
						info->nb_vertices == 2 || \
						!current_vertex->parent->parent)
					tmp2->flag = 1;
		current_vertex = current_vertex->parent;
	}
	return (tmpcur);
}
