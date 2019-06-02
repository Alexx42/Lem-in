/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 01:45:48 by ale-goff          #+#    #+#             */
/*   Updated: 2019/06/02 14:38:24 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_queue			*create_queue(void)
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
	if (queue == NULL || queue->rear == NULL)
		return (1);
	return (0);
}

void			enqueue(t_queue *queue, char *data, t_val *ok)
{
	t_val			*val;

	if (!(val = (t_val *)malloc(sizeof(t_val))))
		return ;
	val->content = data;
	val->next = NULL;
	val->parent = ok;
	if (!queue->front)
		queue->front = val;
	if (queue->rear)
		queue->rear->next = val;
	queue->rear = val;
}

t_val			*dequeue(t_queue *queue)
{
	t_val		*val;

	if (is_empty_queue(queue))
		return (NULL);
	val = queue->front;
	if (queue->front == queue->rear)
	{
		queue->front = NULL;
		queue->rear = NULL;
	}
	else
	{
		queue->front = queue->front->next;
	}
	return (val);
}
