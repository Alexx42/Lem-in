/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 04:34:28 by Alex              #+#    #+#             */
/*   Updated: 2018/12/09 08:20:54 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static	t_nodes 	*init_line(char *str)
{
	t_nodes		*new_line;

	new_line = (t_nodes *)malloc(sizeof(t_nodes));
	if (!new_line)
		return (NULL);
	new_line->data = str;
	new_line->next = NULL;
	return (new_line);
}

static	t_list		*init_list(char *str)
{
	t_list		*new_list;
	t_nodes		*new_line;

	new_line = init_line(str);
	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list || !new_line)
		return (NULL);
	new_list->head = new_line;
	new_list->tail = new_line;
	return (new_list);
}

void			lines_push_back(t_list **lst, char *str)
{
	t_nodes		*new_line;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = init_list(str);
	else
	{
		if ((new_line = init_line(str)) == NULL)
			return ;
		(*lst)->tail->next = new_line;
		(*lst)->tail = new_line;
	}
}