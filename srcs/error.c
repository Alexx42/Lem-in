/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:00:30 by anjansse          #+#    #+#             */
/*   Updated: 2019/05/27 12:28:14 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		send_error(void)
{
	ft_putstr_fd("\x1b[91mERROR\n", 2);
	exit(1);
}

int			check_error(char *str, t_info *info)
{
	(void)info;
	if (str[0] == 'L')
		return (1);
	return (0);
}
