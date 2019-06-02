/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 01:29:12 by ale-goff          #+#    #+#             */
/*   Updated: 2019/06/02 15:08:32 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int					add_vertices(t_graph *graph, t_nodes *node)
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

void				init_struct(t_info **info, t_list **lst,
					t_graph **graph, t_nodes **node)
{
	(*lst) = create_lst();
	create_hash((*lst));
	(*info) = parse_info((*lst)->head);
	(*graph) = new_graph((int)(*info)->nb_vertices);
	(*node) = (*lst)->head;
}

static void			parser(t_info *info, t_graph *graph,
					t_nodes **node)
{
	if (!(ft_atoi((*node)->data)))
		send_error();
	ft_putstr((*node)->data);
	ft_putchar('\n');
	(*node) = (*node)->next;
	while ((*node))
	{
		if (check_error((*node)->data))
			break ;
		ft_putstr((*node)->data);
		ft_putchar('\n');
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

void				get_paths(t_val *tmp, t_graph *graph)
{
	int			v;

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

void				parsing_ants(t_queue *queue, t_val *tmp)
{
	t_info		*info;
	t_list		*lst;
	t_graph		*graph;
	t_nodes		*node;

	init_struct(&info, &lst, &graph, &node);
	parser(info, graph, &node);
	while (bfs(&graph, queue, info))
		;
	if (!graph->path || !graph->path[0])
		send_error();
	graph->nrip = (int *)malloc(sizeof(int) * graph->count + 1);
	get_paths(tmp, graph);
	dispatcher(graph, info);
	delete_list(&lst);
	free_queue(queue);
	free_graph(graph, info);
	free_info(info);
	free_hash();
}
