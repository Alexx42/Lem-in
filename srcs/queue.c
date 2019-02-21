/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 06:16:40 by Alex              #+#    #+#             */
/*   Updated: 2018/12/11 06:37:18 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_queue			*create_queue()
{
	t_queue		*queue;

	if ((queue = (t_queue *)malloc(sizeof(t_queue))) == NULL)
		return (NULL);
	queue->rear = NULL;
	queue->front = NULL;
	return (queue);
}

int				is_empty_queue(t_queue *queue)
{
	if (queue->rear == NULL)
		return (1);
	return (0);
}

void			enqueue(t_queue *queue, char *data)
{
	t_val			*val;

	if ((val = (t_val *)malloc(sizeof(t_val))) == NULL)
		return ;
	val->content = data;
	val->next = NULL;
	if (!queue->front)
		queue->front = val;
	if (queue->rear)
		queue->rear->next = val;
	queue->rear = val;
}

char			*dequeue(t_queue *queue)
{
	char		*content;
	t_val		*val;

	content = NULL;
	val = queue->front;
	if (queue->front)
	{
		content = val->content;
		queue->front = val->next;
		queue->rear = (queue->front ? queue->rear : NULL);
		free(val);
	}
	return (content);
}