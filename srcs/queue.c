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

void			enqueue(t_queue *queue, char *data, t_val *ok)
{
	t_val			*val;

	if ((val = (t_val *)malloc(sizeof(t_val))) == NULL)
		return ;
	val->content = data;
	val->next = NULL;
	val->papa = ok;
	if (!queue->front)
		queue->front = val;
	if (queue->rear)
		queue->rear->next = val;
	queue->rear = val;
}

t_val			*dequeue(t_queue *queue)
{
	t_val		*val;

	val = queue->rear;
	if (is_empty_queue(queue))
		return (NULL);
	if (queue->front == queue->rear)
	{
		queue->front = NULL;
		queue->rear = NULL;
	}
	else
		queue->front = queue->front->next;
	return (val);
}