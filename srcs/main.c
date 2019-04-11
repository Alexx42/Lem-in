#include <lem_in.h>

void		create_hash(t_list *lst)
{
	t_nodes		*node;
	char		*name;
	int			i;

	node = lst->head;
	i = 0;
	while (node && node->data && !ft_strequ(node->data, "##start"))
		node = node->next;
	while (node->data && !ft_strchr(node->data, '-'))
	{
		if (node->data[0] == '#')
			;
		else
		{
			name = malloc(sizeof(char) + ft_clength(node->data, ' '));
			ft_strccpy(name, node->data, ' ');
			insert_data(i, name);
			i++;
		}
		node = node->next;
	}
}

int		main()
{
	parsing_ants();
	return (0);
}