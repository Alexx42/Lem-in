#include <lem_in.h>
#include "../includes/lem_in.h"
#include "../libft/libft.h"

void		create_hash(t_list *lst)
{
	t_nodes		*node;
	char		**split;
	int			i;

	node = lst->head;
	i = 0;
	while (node->data && !ft_strchr(node->data, '-'))
	{
        printf("node = %s\n", node->data);
		if (node->data[0] == '#')
			;
		else
		{
			split = ft_strsplit(node->data, ' ');
			if (split && split[0] && split[1] && split[2])
			{
                printf("%s\n", split[0]);
				insert_data(i, split[0]);
				i++;
			}
		}
		node = node->next;
	}
}

int		main()
{
	parsing_ants();
	return (0);
}