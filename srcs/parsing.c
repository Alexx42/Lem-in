/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 01:29:12 by ale-goff          #+#    #+#             */
/*   Updated: 2019/05/27 01:38:34 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

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

void			bfs_help(t_graph **graph, t_val *current_vertex, t_info *info)
{
	uint32_t	v;
	t_adj		*tmp2;
	t_val		*tmpcur;

	v = -1;
	while (++v < info->nb_vertices)
	{
		tmp2 = (*graph)->adj_list[v];
		while (tmp2)
		{
			tmpcur = get_vertex(tmpcur, current_vertex, info, tmp2);
			current_vertex = tmpcur;
			tmp2 = tmp2->next;
		}
	}
	add_path(graph, current_vertex);
}

void			init_bfs(t_graph **graph, t_queue *queue, t_info *info)
{
	size_t		i;

	i = -1;
	while (++i < info->nb_vertices)
		(*graph)->visited[i] = 0;
	enqueue(queue, info->room_start, NULL);
	(*graph)->visited[search_item(info->room_start)] = 1;
}

int				bfs(t_graph **graph, t_queue *queue, t_info *info)
{
	t_val		*current_vertex;
	t_adj		*tmp;

	init_bfs(graph, queue, info);
	while (!is_empty_queue(queue))
	{
		current_vertex = dequeue(queue);
		tmp = (*graph)->adj_list[search_item(current_vertex->content)];
		while (tmp)
		{
			if (!(*graph)->visited[search_item(tmp->vertex)] && !tmp->flag)
			{
				if (!ft_strcmp(info->room_end, tmp->vertex))
				{
					enqueue(queue, tmp->vertex, current_vertex);
					bfs_help(graph, queue->rear, info);
					return (1);
				}
				enqueue(queue, tmp->vertex, current_vertex);
				(*graph)->visited[search_item(tmp->vertex)] = 1;
			}
			tmp = tmp->next;
		}
	}
	return (0);
}

t_list			*create_lst(void)
{
	t_list		*lst;
	char		*line;
	uint32_t	count_start;
	uint32_t	count_end;

	count_start = 0;
	count_end = 0;
	lst = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp("##start", line))
			count_start++;
		else if (!ft_strcmp("##end", line))
			count_end++;
		push_back(&lst, line);
	}
	if (lst == NULL || count_start != 1 || count_end != 1)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	return (lst);
}

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

void			free_info(t_info *info)
{
	free(info->room_end);
	free(info->room_start);
	free(info);
}

void			free_graph(t_graph *graph, t_info *info)
{
	size_t		i;
	t_adj		*tmp;
	t_adj		*next;

	i = -1;
	while (++i < info->nb_vertices)
	{
		free(graph->nb_ways[i]);
		tmp = graph->adj_list[i];
		while (graph->adj_list[i])
		{
			next = graph->adj_list[i]->next;
			free(graph->adj_list[i]->vertex);
			graph->adj_list[i] = next;
		}
		graph->adj_list[i] = tmp;
		free(graph->adj_list[i]);
		free(graph->path[i]);
	}
	free(graph->visited);
	free(graph->nrip);
	free(graph->path);
	free(graph->nb_ways);
	free(graph->adj_list);
	free(graph);
}

void			free_hash(void)
{
	int			i;

	i = 0;
	while (i < SIZE)
	{
		if (hash_array[i])
		{
			free(hash_array[i]->data);
			free(hash_array[i]);
		}
		i++;
	}
}

void			free_queue(t_queue *queue)
{
	t_val		*tmp;

	while (!is_empty_queue(queue))
	{
		tmp = dequeue(queue);
		free(tmp->content);
		free(tmp);
	}
	free(queue);
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

void			get_paths(t_val *tmp, const t_graph *graph)
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

void			parsing_ants(t_queue *queue)
{
	t_val		*tmp;
	t_info		*info;
	t_list		*lst;
	t_graph		*graph;
	t_nodes		*node;

	tmp = NULL;
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
