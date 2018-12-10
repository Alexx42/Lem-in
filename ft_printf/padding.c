/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 09:17:27 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/04 20:46:04 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		padding_adjustments(t_params *params, t_book *book)
{
	if ((param_is_on(PW3, &params->flags) || param_is_on(PW4, &params->flags))
		&& param_is_on(PW6, &params->flags) == 0 &&
		book->width > 0 && params->type == PW0)
		book->width--;
	if (!param_is_on(PW7, &params->flags) && params->flags >= PW6
		&& params->type == PW0 && book->width > 0)
		book->width--;
	if (book->width > book->prec && param_is_on(PW0, &params->flags))
	{
		if (!param_is_on(PW7, &params->flags) &&
			params->type == PW2 && book->width > 0)
			book->width--;
		else if (book->width > 1 && !param_is_on(PW7, &params->flags) &&
		(params->type == PW3 || params->type == PW4 || params->type == PW5))
			book->width -= 2;
	}
	if (param_is_on(PW1, &params->flags))
		book->prec = book->width;
}

static void		print_prefix(t_params *params, t_book *book, int *count)
{
	if (param_is_on(PW3, &params->flags) &&
		params->flags < PW6 && params->type == PW0)
	{
		putchar_printf(' ', count);
		if (book->width > 0)
			book->width--;
	}
	if (param_is_on(PW6, &params->flags) && params->type == PW0)
		putchar_printf('-', count);
	else if (param_is_on(PW4, &params->flags) && params->type == PW0)
		putchar_printf('+', count);
	else if (!param_is_on(PW7, &params->flags) &&
			param_is_on(PW0, &params->flags) && params->type == PW2)
		putchar_printf('0', count);
	else if (!param_is_on(PW7, &params->flags) &&
			param_is_on(PW0, &params->flags) &&
			(params->type == PW3 || params->type == PW5))
		putstr_printf("0x", count);
	else if (!param_is_on(PW7, &params->flags) &&
			param_is_on(PW0, &params->flags) && params->type == PW4)
		putstr_printf("0X", count);
}

void			padding_left(t_params *params, t_book *book,
							size_t len, int *count)
{
	size_t	tmp;

	padding_adjustments(params, book);
	if (param_is_on(PW5, &params->flags) && book->prec == 0
		&& params->type == PW2 && param_is_on(PW0, &params->flags))
		len++;
	while (!param_is_on(PW2, &params->flags) &&
		book->width > book->prec && book->width > len)
	{
		putchar_printf(' ', count);
		book->width--;
	}
	print_prefix(params, book, count);
	tmp = book->prec;
	while (tmp > len)
	{
		putchar_printf('0', count);
		tmp--;
	}
}

void			padding_right(t_params *params, t_book *book,
							size_t len, int *count)
{
	while (param_is_on(PW2, &params->flags) &&
			book->width > book->prec && book->width > len)
	{
		putchar_printf(' ', count);
		book->width--;
	}
}
