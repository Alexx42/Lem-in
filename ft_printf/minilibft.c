/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 20:34:43 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/14 18:31:20 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_atoi_printf(const char *str)
{
	int		ans;
	int		sign;

	sign = 1;
	ans = 0;
	if (str)
	{
		while (*str && (*str == ' ' || *str == '\n' || *str == '\r'
					|| *str == '\v' || *str == '\f' || *str == '\t'))
			str++;
		if (*str == '-' && str++)
			sign = -1;
		else if (*str == '+' && str++)
			sign = 1;
		while (*str && *str >= '0' && *str <= '9')
			ans = ans * 10 + (*str++ - '0');
	}
	return (sign * ans);
}

int			ft_isdigit_printf(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

size_t		ft_strlen_printf(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

char		*strdup_wchar(wchar_t *s1, size_t *len)
{
	char	*new;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	*len = 0;
	while (s1[*len])
		*len = *len + 1;
	new = (char *)malloc(sizeof(char) * (*len + 1));
	if (!new)
		return (0);
	while (s1[i])
	{
		new[i] = (char)s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char		*ft_strdup_printf(const char *s1)
{
	char	*new;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen_printf(s1) + 1);
	if (!new)
		return (0);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
