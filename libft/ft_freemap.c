/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 22:39:51 by ale-goff          #+#    #+#             */
/*   Updated: 2019/06/01 15:02:50 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freemap(char **arr, int x)
{
	int i;

	i = 0;
	if (!arr || !*arr)
		return ;
	while (i < x)
	{
		if (!arr[i])
			;
		else if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
}
