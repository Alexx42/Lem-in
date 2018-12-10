/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 08:12:05 by Alex              #+#    #+#             */
/*   Updated: 2018/12/09 08:14:10 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_infos		*init_infos()
{
	t_infos		*info;

	if ((info = (t_infos *)malloc(sizeof(t_infos))) == NULL)
		return (NULL);
	info->room_start = NULL;
	info->room_end = NULL;
	return (info);
}