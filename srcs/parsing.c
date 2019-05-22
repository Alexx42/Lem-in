#include <lem_in.h>

void			add_path(t_graph **graph, t_val *current_vertex)
{
	// while (current_vertex->parent)
	// {
		
	// 	current_vertex = current_vertex->content;
	// }
	(*graph)->path[(*graph)->count] = current_vertex;
	(*graph)->count++;
}

void			bfs_help(t_graph **graph, t_val *current_vertex)
{
	int		v;
	t_adj	*tmp2;
	t_val	*tmpcur;

	tmpcur = NULL;
	v = -1;
	while (++v < (*graph)->nb_vertices)
	{
		tmp2 = (*graph)->adj_list[v];
		while (tmp2)
		{
			tmpcur = current_vertex;
			while (current_vertex->parent)
			{
				if (current_vertex->parent)
					if (!ft_strcmp(tmp2->vertex, current_vertex->content))
						if (ft_strcmp(tmp2->vertex, "re"))
							tmp2->flag = 1;
				current_vertex = current_vertex->parent;
			}
			current_vertex = tmpcur;
			tmp2 = tmp2->next;
		}
	}
	add_path(graph, current_vertex);
}

int			bfs(t_graph **graph, t_queue *queue, t_info *info)
{
	t_val		*current_vertex;
	t_adj		*tmp;
	size_t		idx;

	idx = 0;
	while (idx < info->nb_vertices)
	{
		(*graph)->visited[idx] = 0;
		 idx++;
	}
	queue = create_queue();
	enqueue(queue, info->room_start, NULL);
	(*graph)->visited[search_item(info->room_start)] = 1;
	while (!is_empty_queue(queue))
	{
		current_vertex = dequeue(queue);
		tmp = (*graph)->adj_list[search_item(current_vertex->content)];
		while (tmp && tmp->flag == 0)
		{
			if (!(*graph)->visited[search_item(tmp->vertex)])
			{
				if (!ft_strcmp(info->room_end, tmp->vertex))
				{
					enqueue(queue, tmp->vertex, current_vertex);
					bfs_help(graph, queue->rear);
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
	t_val		*tmp;
	t_info		*info;
	t_list		*lst;
	t_graph		*graph;
	t_queue		*queue;

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
	while (bfs(&graph, queue, info))
		;
	ft_putstr("bfs done\n");
	int v = 0;
	graph->nrip = (int *)malloc(sizeof(int) * graph->count + 1);
	while (v < graph->count)
	{
		printf("SALUT\n");
		printf("\nPATH[%d]\n", v);
		graph->nrip[v] = 0;
		tmp = graph->path[v];
		while (graph->path[v]->parent)
		{
			graph->nrip[v]++;
			printf("%s ", graph->path[v]->content);
			graph->path[v] = graph->path[v]->parent;
		}
		graph->path[v] = tmp;
		printf("\nTHIS PATH HAS %d ROOMS\n", graph->nrip[v]);
		v++;
	}
	if (dispatcher(graph, info, tmp))
		ft_putstr("done\n");
}
