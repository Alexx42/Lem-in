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
<<<<<<< HEAD
=======
        //printf("node = %s\n", node->data);
>>>>>>> 04a22392f8c1fc821f2b82d1933d9d20ae3e118b
		if (node->data[0] == '#')
			;
		else
		{
<<<<<<< HEAD
            line = ft_strchr(node->data, ' ');
            if (line != NULL)
            {
                insert_data(i, ft_strsub(node->data, 0, line - node->data));
                i++;
            }
        }
=======
			split = ft_strsplit(node->data, ' ');
			if (split && split[0] && split[1] && split[2])
			{
				//printf("%s\n", split[0]);
				insert_data(i, split[0]);
				i++;
			}
		}
>>>>>>> 04a22392f8c1fc821f2b82d1933d9d20ae3e118b
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
