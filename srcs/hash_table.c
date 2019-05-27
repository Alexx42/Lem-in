/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 06:47:51 by Alex              #+#    #+#             */
/*   Updated: 2019/05/27 15:07:27 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int			hash_code(int key)
{
	return (key % SIZE);
}

int			search_item(char *data)
{
	int			i;

	i = 0;
	while (i < SIZE)
	{
		if (g_hash_array[i] && !ft_strcmp(g_hash_array[i]->data, data))
			return (g_hash_array[i]->key);
		i++;
	}
	return (-1);
}

void		insert_data(int key, char *data)
{
	t_hash		*item;
	int			hash_idx;

	if ((item = malloc(sizeof(t_hash))) == NULL)
		return ;
	item->data = data;
	item->key = key;
	hash_idx = hash_code(key);
	while (g_hash_array[hash_idx] != NULL && g_hash_array[hash_idx]->key != -1)
	{
		++hash_idx;
		hash_idx %= SIZE;
	}
	if (g_hash_array[search_item(data)])
		send_error();
	g_hash_array[hash_idx] = item;
}
