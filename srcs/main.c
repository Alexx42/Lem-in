/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 04:08:10 by Alex              #+#    #+#             */
/*   Updated: 2018/12/11 07:37:33 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		create_hash(t_list *lst)
{
	t_nodes		*node;
	char		*name;
	int			i;

	node = lst->head;
	i = 0;
	while (node && node->data && !ft_strequ(node->data, "##start"))
		node = node->next;
	while (node->data && !ft_strchr(node->data, '-'))
	{
		if (node->data[0] == '#')
			;
		else
		{
			name = malloc(sizeof(char) + ft_clength(node->data, ' '));
			ft_strccpy(name, node->data, ' ');
			insert_data(i, name);
			i++;
		}
		node = node->next;
	}
}

t_list		*append_list()
{
	t_list		*lst;
	char		*line;

	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	lst = NULL;
	line = NULL;
	while (get_next_line(0, &line) > 0)
		lines_push_back(&lst, line);
	return (lst);
}

int			main(void)
{
	t_list		*lst;

	lst = append_list();
	create_hash(lst);
	if (general_parsing(lst))
		ft_putstr_fd("Error", 2);
	return (0);
}