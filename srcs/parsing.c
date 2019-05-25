#include <lem_in.h>
#include "../libft/libft.h"
#include "../includes/lem_in.h"

void			add_path(t_graph **graph, t_val *current_vertex)
{
	(*graph)->path[(*graph)->count] = current_vertex;
	(*graph)->count++;
}

void			bfs_help(t_graph **graph, t_val *current_vertex, t_info *info)
{
	uint32_t v;
	t_adj	*tmp2;
	t_val	*tmpcur;

	v = -1;
	while (++v < info->nb_vertices)
	{
		tmp2 = (*graph)->adj_list[v];
		while (tmp2)
		{
			tmpcur = current_vertex;
			while (current_vertex->parent)
			{
				if (current_vertex->parent)
					if (!ft_strcmp(tmp2->vertex, current_vertex->content))
						 if (ft_strcmp(tmp2->vertex, info->room_end) || info->nb_vertices == 2 || !current_vertex->parent->parent)
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
	size_t		i;

	i = 0;
	while (i < info->nb_vertices)
	{
		(*graph)->visited[i] = 0;
		i++;
	}
	queue = create_queue();
	enqueue(queue, info->room_start, NULL);
	(*graph)->visited[search_item(info->room_start)] = 1;
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

t_list			*create_lst()
{
	t_list		*lst;
	char		*line;
	uint32_t 	count_start;
	uint32_t 	count_end;

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
		exit (1);
	}
	return (lst);
}

int     add_vertices(t_graph *graph, t_nodes *node)
{
	char		**nb;

	nb = ft_strsplit(node->data, '-');
    if (search_item(nb[0]) == -1 || search_item(nb[1]) == -1)
        return (1);
	add_edge(graph, nb[0], nb[1]);
	return (0);
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
	info = parse_info(lst->head);
	graph = new_graph((int)info->nb_vertices);
	while (lst && lst->head)
	{
		ft_putstr(lst->head->data);
		ft_putchar('\n');
        if (check_error(lst->head->data))
            break ;
		if (ft_strequ(lst->head->data, "##start"))
			parse_end_start(info, 0, &lst->head);
		else if (ft_strequ(lst->head->data, "##end"))
			parse_end_start(info, 1, &lst->head);
		else if (ft_strchr(lst->head->data, '-') != NULL)
			if (add_vertices(graph, lst->head))
				break ;
		lst->head = lst->head->next;
	}
	ft_putchar('\n');
//    print_graph(graph);
//    print_hash();
	while (bfs(&graph, queue, info))
		;
	if (!graph->path || !graph->path[0])
	{
		ft_putstr_fd("ERROR\n", 2);
		exit (1);
	}
	int v = 0;
	graph->nrip = (int *)malloc(sizeof(int) * graph->count + 1);
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
	if (dispatcher(graph, info))
		exit(0);
}
