/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 01:41:47 by ale-goff          #+#    #+#             */
/*   Updated: 2019/06/02 14:19:00 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include "../libft/libft.h"

static t_nodes		*init_line(char *str)
{
	t_nodes		*line;

	line = (t_nodes*)malloc(sizeof(t_nodes));
	if (line == NULL)
		return (NULL);
	line->data = str;
	line->next = NULL;
	return (line);
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

t_list				*create_lst(void)
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
		send_error();
	return (lst);
}

void				delete_list(t_list **head)
{
	t_nodes		*current;
	t_nodes		*next;

	current = (*head)->head;
	while (current != NULL)
	{
		next = current->next;
		free(current->data);
		free(current);
		current = next;
	}
	*head = NULL;
}

void				push_back(t_list **lst, char *str)
{
	t_nodes			*new_line;

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
