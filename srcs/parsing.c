#include <lem_in.h>

int			bfs(t_graph *graph, t_queue *queue, t_info *info)
{
	t_val	*current_vertex;
	t_adj	*tmp;
	int		idx;

	enqueue(queue, info->room_start, NULL);

	idx = 0;
	while (!is_empty_queue(queue))
	{
		current_vertex = dequeue(queue);
		tmp = graph->adj_list[search_item(current_vertex->content)];
		// graph->nb_ways[idx][0]++;
		while (tmp)
		{
			if (!graph->visited[search_item(tmp->vertex)])
			{
				if (!ft_strcmp(info->room_end, tmp->vertex))
				{
					//add path
					return 1;
				}
				enqueue(queue, tmp->vertex, current_vertex);
				remove_idx_elements(&tmp, search_item(current_vertex->content));
			}
			tmp = tmp->next;
		}
	}

	while (current_vertex)
	{
		if (current_vertex->parent)
			printf("%s ", current_vertex->parent->content);
		current_vertex = current_vertex->parent;
	}
	return (0);
}

t_list			*create_lst()
{
	t_list		*lst;
	char		*line;

	lst = NULL;
	while (get_next_line(0, &line) > 0)
		push_back(&lst, line);
	if (lst == NULL)
	{
		ft_putstr_fd("file empty\n", 2);
		exit (1);
	}
	return (lst);
}

void			add_vertices(t_graph *graph, t_nodes *node)
{
	char		**nb;

	nb = ft_strsplit(node->data, '-');
	add_edge(graph, nb[0], nb[1]);
}

void			parsing_ants()
{
	t_info		*info;
	t_queue		*queue;
	t_list		*lst;
	t_graph		*graph;
	
	queue = create_queue();
	lst = create_lst();
	create_hash(lst);
	print_hash();
	info = parse_info(lst->head);
	graph = new_graph(info->nb_vertices);
	while (lst && lst->head)
	{
		if (ft_strequ(lst->head->data, "##start"))
			parse_end_start(info, 0, &lst->head);
		else if (ft_strequ(lst->head->data, "##end"))
			parse_end_start(info, 1, &lst->head);
		else if (ft_strchr(lst->head->data, '-') != NULL)
			add_vertices(graph, lst->head);
		lst->head = lst->head->next;
	}
	// print_graph(graph);
	// print_info(info);
	while (bfs(graph, queue, info))
		;
	print_graph(graph);
}