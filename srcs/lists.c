
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

void				remove_idx_elements(t_adj **lst, char *str) {
	// int		i;

	// while ((*lst)) {
	// 	printf("val = %s ", (*lst)->vertex);
	// 	(*lst) = (*lst)->next;
	// }
	t_adj *tmp = *lst;
	t_adj *prev;
	if (tmp != NULL && !ft_strcmp(tmp->vertex, str)) {
		*lst = tmp->next;
		free(tmp);
		return ;
	}
	while (tmp != NULL && ft_strcmp(tmp->vertex, str)) {
		prev = tmp;
		tmp = tmp->next;
	}
	if (prev == NULL) return ;
	prev->flag = 1;
	// free(tmp);
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