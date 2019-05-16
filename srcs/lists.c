
#include <lem_in.h>

static t_nodes		*init_line(char *str)
{
	t_nodes		*line;

	line = (t_nodes*)malloc(sizeof(t_nodes));
	if (line == NULL)
		return (NULL);
	line->data = str;
	line->next = NULL;
	return (line);
}

static	t_list		*init_list(char *str)
{
	t_list		*new_list; 
	t_nodes		*new_line;

	new_line = init_line(str);
	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list || !new_line)
		return (NULL);
	new_list->head = new_line;
	new_list->tail = new_line;
	return (new_list);
}

void				remove_idx_elements(t_adj **lst, int idx) {
	int		i;

	i = 0;
	if (!*lst) {
		return ;
	}
	t_adj *tmp = (*lst);
	t_adj	*next;
	if (idx == 0) {
		(*lst) = tmp->next;
		free(tmp);
		return ;
	}
	while (tmp != NULL && i < idx - 1) {
		tmp = tmp->next;
	}
	if (tmp == NULL || tmp->next == NULL) {
		return ;
	}
	next = (tmp)->next->next;
	free(tmp->next);
	tmp->next = next;
}

void				push_back(t_list **lst, char *str)
{
	t_nodes		*new_line;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = init_list(str);
	else
	{
		if ((new_line = init_line(str)) == NULL)
			return ;
		(*lst)->tail->next = new_line;
		(*lst)->tail = new_line;
	} 
}