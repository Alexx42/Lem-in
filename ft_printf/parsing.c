/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:11:29 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/14 18:28:29 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*flags_parsing(char *fmt, t_params *params)
{
	int		i;
	int		k;

	i = 1;
	k = 0;
	while (*fmt && i)
	{
		k = 1;
		i = 0;
		if (*fmt == '#' && (i = 1))
			set_params(PW0, &params->flags);
		else if (*fmt == '0' && (i = 1))
			set_params(PW1, &params->flags);
		else if (*fmt == '-' && (i = 1))
			set_params(PW2, &params->flags);
		else if (*fmt == ' ' && (i = 1))
			set_params(PW3, &params->flags);
		else if (*fmt == '+' && (i = 1))
			set_params(PW4, &params->flags);
		fmt++;
	}
	if (k)
		fmt--;
	return (fmt);
}

static char		*lmod_parsing(char *fmt, t_params *params)
{
	if (*fmt == 'h' && *(fmt + 1) == 'h' && fmt++)
		set_params(PW0, &params->lmod);
	else if (*fmt == 'h')
		set_params(PW1, &params->lmod);
	else if (*fmt == 'l' && *(fmt + 1) == 'l' && fmt++)
		set_params(PW2, &params->lmod);
	else if (*fmt == 'l')
		set_params(PW3, &params->lmod);
	else if (*fmt == 'j')
		set_params(PW4, &params->lmod);
	else if (*fmt == 'z')
		set_params(PW5, &params->lmod);
	else
		return (fmt);
	fmt++;
	return (fmt);
}

static char		*type_parsing(char *fmt, t_params *params)
{
	if (*fmt == 'd' || *fmt == 'i')
		set_params(PW0, &params->type);
	else if (*fmt == 'u' || *fmt == 'D')
		set_params(PW1, &params->type);
	else if (*fmt == 'U')
		set_params(PW6, &params->flags);
	else if (*fmt == 'o' || *fmt == 'O')
		set_params(PW2, &params->type);
	else if (*fmt == 'x')
		set_params(PW3, &params->type);
	else if (*fmt == 'X')
		set_params(PW4, &params->type);
	else if (*fmt == 'p')
		set_params(PW5, &params->type);
	else if (*fmt == 's')
		set_params(PW6, &params->type);
	else if (*fmt == 'c' || *fmt == 'C')
		set_params(PW7, &params->type);
	else if (*fmt == '%')
		set_params(PW6, &params->lmod);
	else if (*fmt == 'S')
		set_params(PW7, &params->lmod);
	return (fmt);
}

char			*parsing(char *fmt, t_params *params, t_book *book)
{
	fmt = flags_parsing(fmt, params);
	if (*fmt && *fmt != '.')
		book->width = ft_atoi_printf(fmt);
	while (*fmt && ft_isdigit_printf(*fmt))
		fmt++;
	if (*fmt && *fmt == '.' && fmt++)
	{
		set_params(PW5, &params->flags);
		unset_params(PW1, &params->flags);
		book->prec = ft_atoi_printf(fmt);
	}
	while (*fmt && ft_isdigit_printf(*fmt))
		fmt++;
	fmt = lmod_parsing(fmt, params);
	fmt = type_parsing(fmt, params);
	if (param_is_on(PW2, &params->flags))
		unset_params(PW1, &params->flags);
	if (param_is_on(PW4, &params->flags))
		unset_params(PW3, &params->flags);
	return (fmt);
}
