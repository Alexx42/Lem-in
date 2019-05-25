#include <lem_in.h>
#include "../includes/lem_in.h"
#include "../libft/libft.h"

void		create_hash(t_list *lst)
{
	t_nodes		*node;
	t_nodes		*tmp;
    char        *line;
	int			i;

	node = lst->head;
	tmp = lst->head;
	i = 0;
	while (node->data && !ft_strchr(node->data, '-'))
	{
		if (node->data[0] == '#')
			;
		else
		{
            line = ft_strchr(node->data, ' ');
            if (line != NULL)
            {
                insert_data(i, ft_strsub(node->data, 0, line - node->data));
                i++;
            }
        }
		node = node->next;
	}
	lst->head = tmp;
}

int		main()
{
	parsing_ants();
    system("leaks lem-in");
	return (0);
}
