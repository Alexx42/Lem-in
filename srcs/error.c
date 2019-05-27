/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:00:30 by anjansse          #+#    #+#             */
/*   Updated: 2019/05/27 15:08:34 by anjansse         ###   ########.fr       */
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

void			send_error(void)
{
	ft_putstr_fd("\x1b[91mERROR\n", 2);
	exit(1);
}

int				check_error(char *str, t_info *info)
{
	(void)info;
	if (str[0] == 'L')
		return (1);
	if (str[0] != '#' && (elem_in_array(ft_strsplit(str, ' ')) != 3 && \
				elem_in_array(ft_strsplit(str, '-')) != 2))
		send_error();
	return (0);
}
