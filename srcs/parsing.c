#include <lem_in.h>

int			bfs(t_graph *graph, t_queue *queue, t_info *info)
{
	t_val	*current_vertex;
	char	*adj_vertex;
	t_adj	*tmp;

	graph->visited[search_item(info->room_start)] = 1;
	enqueue(queue, info->room_start, NULL);
	while (!is_empty_queue(queue))
	{
		current_vertex = dequeue(queue);
		tmp = graph->adj_list[search_item(current_vertex->content)];
		while (tmp)
		{
			adj_vertex = tmp->vertex;
			if (graph->visited[search_item(adj_vertex)] == 0)
			{
				graph->visited[search_item(adj_vertex)] = 1;
				enqueue(queue, adj_vertex, current_vertex);
			}
			tmp = tmp->next;
		}
	}
			int i = 3;
	while (current_vertex)
	{
		if (current_vertex->papa)
			ft_printf("way(%d) = %s\n", i--, current_vertex->papa->content);
		current_vertex = current_vertex->papa;
	}
	return (1);
}

t_list			*create_lst()
{
	t_list		*lst;
	char		*line;

	lst = NULL;
	while (get_next_line(0, &line) > 0)
		push_back(&lst, line);
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
	print_graph(graph);
	print_info(info);
	bfs(graph, queue, info);
}