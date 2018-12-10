/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 06:53:04 by Alex              #+#    #+#             */
/*   Updated: 2018/12/10 14:08:14 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static size_t	number_vertices(t_list *lst)
{
	int		nb_vertices;
	t_nodes	*node;

	node = lst->head;
	nb_vertices = 0;
	node = node->next;
	while (node && !ft_strchr(node->data, '-'))
	{
		if (ft_strchr(node->data, '#') == NULL)
			nb_vertices++;
		node = node->next;
	}
	return (nb_vertices);
}

static t_infos	*parse_infos(t_list *lst)
{
	t_infos		*info;
	t_nodes		*node;
	static int	count = 0;

	node = lst->head;
	info = init_infos();
	while (node)
	{
		if (count == 0)
			info->nb_ants = (size_t)ft_atoi(node->data);
		if (ft_strequ(node->data, "##start"))
			info->room_start = node->next->data;
		if (ft_strequ(node->data, "##end"))
			info->room_end = node->next->data;
		node = node->next;
		count = 1;
	}
	return (info);
}

static void		parser_room(t_graph *graph, t_list *lst)
{
	t_nodes		*node;
	char		**split;

	node = lst->head;
	while (!ft_strchr(node->data, '-'))
		node = node->next;
	while (node)
	{
		if (node->data[0] == '#')
			;
		else if (ft_strchr(node->data, '-'))
		{
			split = ft_strsplit(node->data, '-');
			add_edge(graph, split[0], split[1]);
		}
		node = node->next;
	}
}

void			general_parsing(t_list *lst)
{
	int			nb_vertices;
	t_graph		*graph;
	t_infos		*infos;

	nb_vertices = number_vertices(lst);
	graph = new_graph(nb_vertices);
	infos = parse_infos(lst);
	parser_room(graph, lst);
	print_graph(graph);
	printf("nb = %d\n", graph->nb_vertices);
	print_infos(infos);
}