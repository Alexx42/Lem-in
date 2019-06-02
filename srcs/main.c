/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 01:09:11 by ale-goff          #+#    #+#             */
/*   Updated: 2019/06/02 14:49:22 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include "../includes/lem_in.h"
#include "../libft/libft.h"

void		create_hash(t_list *lst)
{
	t_nodes		*node;
	t_nodes		*tmp;
	char		*line;
	int			i;

	node = lst->head;
	tmp = lst->head;
	i = 0;
	while (node && node->data && !ft_strchr(node->data, '-'))
	{
		if (node->data[0] != '#')
		{
			line = ft_strchr(node->data, ' ');
			if (line != NULL)
			{
				insert_data(i, ft_strsub(node->data, 0, line - node->data));
				i++;
			}
		}
		node = node->next;
	}
	lst->head = tmp;
}

int			main(int ac, char **av)
{
	t_queue		*queue;
	t_val		*tmp;

	(void)av;
	if (ac > 1)
		send_error();
	tmp = NULL;
	queue = create_queue();
	parsing_ants(queue, tmp);
	return (0);
}
