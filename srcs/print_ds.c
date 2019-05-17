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
			printf("%d ", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void		print_hash()
{
	int			i;

	i = 0;
	while (i < 25)
	{
		if (hash_array[i] != NULL)
			printf(" (%d,%s)",hash_array[i]->key,hash_array[i]->data);
		else
			printf(" ~~ ");
		i++;
	}
	printf("\n");
}

void		print_graph(t_graph *graph)
{
	int		v;
	t_adj	*tmp;

	v = 0;
	while (v < graph->nb_vertices)
	{
		tmp = graph->adj_list[v];
		while (tmp)
		{
			graph->nb_ways[v][1]++;
			tmp = tmp->next;
		}
		v++;
	}

	tmp = NULL;
	v = 0;
	while (v < graph->nb_vertices)
	{
		tmp = graph->adj_list[v];
		printf("Adjacency list of vertex %s\n", hash_array[v]->data);
		while (tmp)
		{
			printf("%s -> ", tmp->vertex);
			tmp = tmp->next;
		}
		printf("\n");
		v++;
	}
}