/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:00:30 by anjansse          #+#    #+#             */
/*   Updated: 2019/06/02 15:22:44 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static int		elem_in_array(char **array)
{
	int		i;

	i = -1;
	while (array[++i])
		;
	return (i);
}

static void		check_coord(char **array)
{
	if (*array)
	{
		array++;
		while (*array)
		{
			if (!(ft_isdigit(**array)))
				send_error();
			array++;
		}
	}
}

void			send_error(void)
{
	ft_putstr_fd("\x1b[91mERROR\n", 2);
	exit(1);
}

int				check_error(char *str)
{
	char		**split;
	char		**split2;

	if (str[0] == 'L')
		return (1);
	split = ft_strsplit(str, ' ');
	split2 = ft_strsplit(str, '-');
	check_coord(split);
	if (str[0] != '#' && (elem_in_array(split) != 3 && \
				elem_in_array(split2) != 2))
		send_error();
	if (split)
	{
		if (split[0] && split[1] && split[2])
			free(split[2]);
		ft_freemap(split, 2);
	}
	if (split2)
		ft_freemap(split2, 2);
	return (0);
}
