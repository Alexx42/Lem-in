/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:16:38 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/31 19:49:32 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		init_structs(t_params **params, t_book **book, int reset)
{
	if (reset == 0)
	{
		if (!(*params = (t_params *)malloc(sizeof(t_params))))
			return (-1);
		if (!(*book = (t_book *)malloc(sizeof(t_book))))
			return (-1);
	}
	(*params)->flags = 0;
	(*params)->lmod = 0;
	(*params)->type = 0;
	(*book)->width = 0;
	(*book)->prec = 0;
	return (0);
}
