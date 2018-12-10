/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all_nbs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:47:45 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/04 20:47:12 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			lmod_signed(t_params *params, va_list ap)
{
	if (params->lmod == PW0)
		return ((signed char)va_arg(ap, int));
	if (params->lmod == PW1)
		return ((short)va_arg(ap, int));
	if (params->lmod == PW2)
		return (va_arg(ap, long long));
	if (params->lmod == PW3)
		return (va_arg(ap, long));
	if (params->lmod == PW4)
		return (va_arg(ap, intmax_t));
	if (params->lmod == PW5)
		return (va_arg(ap, size_t));
	return (0);
}

unsigned long long	lmod_unsigned(t_params *params, va_list ap)
{
	if (params->lmod == PW0)
		return ((unsigned char)va_arg(ap, unsigned int));
	if (params->lmod == PW1 && param_is_on(PW6, &params->flags))
		return (va_arg(ap, unsigned long));
	if (params->lmod == PW1)
		return ((unsigned short)va_arg(ap, unsigned int));
	if (params->lmod == PW2)
		return (va_arg(ap, unsigned long long));
	if (params->lmod == PW3)
		return (va_arg(ap, unsigned long));
	if (params->lmod == PW4)
		return (va_arg(ap, uintmax_t));
	if (params->lmod == PW5)
		return (va_arg(ap, size_t));
	if (param_is_on(PW6, &params->flags))
		return (va_arg(ap, unsigned long));
	return (0);
}

void				print_signed(long long nb, int *count)
{
	if (nb == LLONG_MIN)
	{
		putstr_printf("9223372036854775808", count);
		return ;
	}
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
		print_signed(nb / 10, count);
	putchar_printf(nb % 10 + '0', count);
}

void				print_unsigned(unsigned long long nb,
					unsigned long long base, t_params *params, int *count)
{
	if (nb >= base)
		print_unsigned(nb / base, base, params, count);
	if (nb % base >= 10)
	{
		if (params->type == PW4)
			putchar_printf(nb % base + 55, count);
		else
			putchar_printf(nb % base + 87, count);
	}
	else
		putchar_printf(nb % base + '0', count);
}
