/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 06:47:51 by Alex              #+#    #+#             */
/*   Updated: 2018/12/10 08:30:06 by Alex             ###   ########.fr       */
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
		if (hash_array[i] && !ft_strcmp(hash_array[i]->data, data))
			return (hash_array[i]->key);
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
	while (hash_array[hash_idx] != NULL && hash_array[hash_idx]->key != -1)
	{
		++hash_idx;
		hash_idx %= SIZE;
	}
	hash_array[hash_idx] = item;
}