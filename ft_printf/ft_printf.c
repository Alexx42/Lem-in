/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:30:39 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/04 20:39:10 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_cases(char *fmt, int *count, va_list ap)
{
	t_params	*params;
	t_book		*book;

	if (init_structs(&params, &book, 0) == -1)
		return ;
	while (*fmt)
	{
		if (*fmt == '%' && fmt++)
		{
			init_structs(&params, &book, 1);
			fmt = parsing(fmt, params, book);
			print_conv(params, book, ap, count);
		}
		else
			putchar_printf(*fmt, count);
		fmt++;
	}
	free(params);
	free(book);
	va_end(ap);
}

int				ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			*count;
	int			ret;

	if (!(count = (int *)malloc(sizeof(int))))
		return (0);
	*count = 0;
	va_start(ap, fmt);
	ft_cases((char *)fmt, count, ap);
	ret = *count;
	free(count);
	return (ret);
}
