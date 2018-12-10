/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 21:40:59 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/14 18:31:40 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		putchar_printf(char c, int *count)
{
	write(1, &c, 1);
	*count = *count + 1;
}

void		putstr_printf(char *s, int *count)
{
	size_t	len;

	len = ft_strlen_printf(s);
	write(1, s, len);
	*count = *count + len;
}

void		print_char(t_params *params, t_book *book, va_list ap, int *count)
{
	while (book->width > 1 && !param_is_on(PW2, &params->flags))
	{
		putchar_printf(' ', count);
		book->width--;
	}
	if (params->lmod == PW6)
		putchar_printf('%', count);
	else
		putchar_printf(va_arg(ap, int), count);
	while (book->width > 1 && param_is_on(PW2, &params->flags))
	{
		putchar_printf(' ', count);
		book->width--;
	}
}

void		print_str(t_params *params, t_book *book, va_list ap, int *count)
{
	char	*str;
	size_t	len;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen_printf(str);
	if (book->prec < len && param_is_on(PW5, &params->flags))
		len = book->prec;
	while (book->width > len && !param_is_on(PW2, &params->flags))
	{
		putchar_printf(' ', count);
		book->width--;
	}
	write(1, str, len);
	*count = *count + len;
	while (book->width > len && param_is_on(PW2, &params->flags))
	{
		putchar_printf(' ', count);
		book->width--;
	}
}
