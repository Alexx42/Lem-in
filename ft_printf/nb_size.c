/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:47:41 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/01 19:41:26 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		signed_nb_size(long long nb)
{
	size_t		count;

	count = 1;
	if (nb == LLONG_MIN)
		return (19);
	if (nb < 0)
		nb = -nb;
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

size_t		unsigned_nb_size(unsigned long long nb, unsigned long long base)
{
	size_t		count;

	count = 1;
	while (nb >= base)
	{
		nb /= base;
		count++;
	}
	return (count);
}
