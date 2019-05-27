/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 14:10:18 by anjansse          #+#    #+#             */
/*   Updated: 2019/05/27 01:28:10 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			in_previous(int *n, int end, int begin)
{
	while (begin < end)
	{
		if (n[begin] == n[begin + 1] || n[begin] == n[end])
			return (1);
		begin++;
	}
	return (0);
}

void		reverse_path(t_val **path)
{
	t_val	*prev;
	t_val	*current;
	t_val	*next;

	prev = NULL;
	current = *path;
	next = NULL;
	while (current->parent != NULL)
	{
		next = current->parent;
		current->parent = prev;
		prev = current;
		current = next;
	}
	*path = prev;
}

void		print_ant_path(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

int			*init_id(int *array, int max)
{
	int		i;

	i = 0;
	while (i < max)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}
