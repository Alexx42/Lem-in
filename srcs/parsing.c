/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 01:29:12 by ale-goff          #+#    #+#             */
/*   Updated: 2019/05/27 10:40:32 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int				add_vertices(t_graph *graph, t_nodes *node)
{
	char		*line;
	char		*line2;
	char		*line3;

	line = ft_strchr(node->data, '-');
	line2 = ft_strsub(node->data, 0, line - node->data);
	line3 = ft_strsub(node->data, (unsigned int)(ft_strlen(line2) + 1),
			ft_strlen(node->data));
	add_edge(graph, line2, line3);
	return (0);
}

void			init_struct(t_info **info, t_list **lst,
				t_graph **graph, t_nodes **node)
{
	(*lst) = create_lst();
	create_hash((*lst));
	(*info) = parse_info((*lst)->head);
	(*graph) = new_graph((int)(*info)->nb_vertices);
	(*node) = (*lst)->head;
}

void			parseur(t_info *info, t_graph *graph,
				t_nodes **node)
{
	while ((*node))
	{
		ft_putstr((*node)->data);
		ft_putchar('\n');
		if (check_error((*node)->data))
			break ;
		if (ft_strequ((*node)->data, "##start"))
			parse_end_start(info, 0, node);
		else if (ft_strequ((*node)->data, "##end"))
			parse_end_start(info, 1, node);
		else if (ft_strchr((*node)->data, '-') != NULL)
			if (add_vertices(graph, (*node)))
				break ;
		(*node) = (*node)->next;
	}
}

void			get_paths(t_val *tmp, t_graph *graph)
{
	int		v;

	v = 0;
	while (v < graph->count)
	{
		graph->nrip[v] = 0;
		tmp = graph->path[v];
		while (graph->path[v]->parent)
		{
			graph->nrip[v]++;
			graph->path[v] = graph->path[v]->parent;
		}
		graph->path[v] = tmp;
		v++;
	}
	ft_putchar('\n');
}

void			parsing_ants(t_queue *queue, t_val *tmp)
{
	t_info		*info;
	t_list		*lst;
	t_graph		*graph;
	t_nodes		*node;

	init_struct(&info, &lst, &graph, &node);
	parseur(info, graph, &node);
	while (bfs(&graph, queue, info))
		;
	if (!graph->path || !graph->path[0])
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	graph->nrip = (int *)malloc(sizeof(int) * graph->count + 1);
	get_paths(tmp, graph);
	if (dispatcher(graph, info))
		ft_putchar('\n');
	delete_list(&lst);
	free_queue(queue);
	free_graph(graph, info);
	free_info(info);
	free_hash();
}
