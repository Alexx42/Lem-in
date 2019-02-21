/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 06:53:04 by Alex              #+#    #+#             */
/*   Updated: 2018/12/11 07:14:41 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static int		number_vertices(t_list *lst)
{
	int nb_vertices;
	t_nodes		*node;
	int			count_start;
	int			count_end;

	count_start = 0;
	count_end = 0;
	node = lst->head;
	nb_vertices = 0;
	while (node && ft_strcmp(node->data, "##start") != 0)
		node = node->next;
	while (node && !ft_strchr(node->data, '-'))
	{
		if (!ft_strcmp(node->data, "##start"))
			count_start++;
		if (!ft_strcmp(node->data, "##end"))
			count_end++;
		if (node->data[0] != '#')
			nb_vertices++;
		node = node->next;
	}
	if (count_start != 1 || count_end != 1)
		return (-1);
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
		{
			info->nb_ants = (size_t)ft_atoi(node->data);
			count = 1;
		}
		if (!ft_strcmp(node->data, "##start"))
		{
			info->room_start = malloc(sizeof(char) * ft_clength(node->next->data, ' '));
			ft_strccpy(info->room_start, node->next->data, ' ');
		}
		if (!ft_strcmp(node->data, "##end"))
		{
			info->room_end = malloc(sizeof(char) * ft_clength(node->next->data, ' '));
			ft_strccpy(info->room_end, node->next->data, ' ');
		}
		node = node->next;
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

int 			general_parsing(t_list *lst)
{
	int			nb_vertices;
	t_graph		*graph;
	t_infos		*infos;

	if ((nb_vertices = number_vertices(lst)) == -1)
		return (1);
	graph = new_graph(nb_vertices);
	infos = parse_infos(lst);
	parser_room(graph, lst);
	general_algorithm(graph, infos);
	return (0);
}