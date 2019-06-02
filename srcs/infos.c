/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 01:21:18 by ale-goff          #+#    #+#             */
/*   Updated: 2019/06/01 15:21:59 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include "../includes/lem_in.h"
#include "../libft/libft.h"

static t_info		*init_info(void)
{
	t_info		*info;

	info = (t_info*)malloc(sizeof(t_info));
	info->nb_ants = 0;
	info->room_start = NULL;
	info->check = 0;
	info->room_end = NULL;
	info->nb_vertices = 0;
	return (info);
}

t_info				*parse_info(t_nodes *node)
{
	t_info		*info;

	info = init_info();
	if (!(info->nb_ants = ft_atoi(node->data)))
		send_error();
	info->check |= ANT;
	if (info->nb_ants < 0)
		send_error();
	parse_nb_vertices(node, info);
	return (info);
}

void				parse_nb_vertices(t_nodes *node, t_info *info)
{
	while (node)
	{
		if (node->data[0] == '#')
			;
		else if (ft_strchr(node->data, ' ') &&
		ft_strchr(node->data, '-') == NULL)
			info->nb_vertices++;
		node = node->next;
	}
	if (info->nb_vertices <= 1)
		send_error();
}

void				parse_end_start(t_info *info, char flag, t_nodes **node)
{
	char			*line;

	ft_putstr((*node)->next->data);
	ft_putchar('\n');
	while ((*node)->next->data[0] == '#')
		(*node) = (*node)->next;
	(*node) = (*node)->next;
	line = ft_strchr((*node)->data, ' ');
	if (!flag)
	{
		info->room_start = ft_strsub((*node)->data, 0, line - (*node)->data);
		if (info->check & START)
			send_error();
		info->check |= START;
	}
	else
	{
		info->room_end = ft_strsub((*node)->data, 0, line - (*node)->data);
		if (info->check & END)
			send_error();
		info->check |= END;
	}
}
