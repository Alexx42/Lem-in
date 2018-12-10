/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 18:43:27 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/31 19:22:11 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_params(unsigned char bitnb, unsigned char *c)
{
	unsigned char	i;

	i = 1;
	while (i < bitnb)
		i <<= 1;
	*c = *c | i;
}

void		unset_params(unsigned char bitnb, unsigned char *c)
{
	unsigned char	i;

	i = 1;
	while (i < bitnb)
		i <<= 1;
	i = i ^ 255;
	*c = *c & i;
}

int			param_is_on(unsigned char bitnb, unsigned char *c)
{
	unsigned char	i;

	i = 1;
	while (i < bitnb)
		i <<= 1;
	return ((*c & i) ? 1 : 0);
}
