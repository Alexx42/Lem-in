/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:27:19 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/04 20:52:34 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_unsigned_len_and_base(t_params *params,
			unsigned long long nb, size_t *len, int *base)
{
	if (params->type == PW1)
	{
		*len = unsigned_nb_size(nb, 10);
		*base = 10;
	}
	if (params->type == PW2)
	{
		*len = unsigned_nb_size(nb, 8);
		*base = 8;
	}
	if (params->type == PW3 || params->type == PW4 || params->type == PW5)
	{
		*len = unsigned_nb_size(nb, 16);
		*base = 16;
	}
}

int			print_or_nah(t_params *params, t_book *book)
{
	if (param_is_on(PW7, &params->flags) &&
		(params->type == PW3 || params->type == PW4)
		&& param_is_on(PW5, &params->flags) && book->prec == 0)
		return (0);
	if (param_is_on(PW7, &params->flags) && param_is_on(PW5, &params->flags)
		&& book->prec == 0 && params->type == PW2
		&& !param_is_on(PW0, &params->flags))
		return (0);
	return (1);
}
