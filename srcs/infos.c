#include <lem_in.h>

static t_info		*init_info()
{
	t_info		*info;

	info = (t_info*)malloc(sizeof(t_info));
	info->nb_ants = 0;
	info->room_start = NULL;
	info->room_end = NULL;
	info->nb_vertices = 0;
	return (info);
}

t_info				*parse_info(t_nodes *node)
{
	t_info		*info;

	info = init_info();
	while (node->data)
	{
		if (node->data[0] != '#')
			break ;
	}
	info->nb_ants = ft_atoi(node->data);
	parse_nb_vertices(node, info);
	return (info);
}

void			parse_nb_vertices(t_nodes *node, t_info *info)
{
	while (node)
	{
		if (node->data[0] == '#')
			;
		else if (ft_strchr(node->data, ' ') && ft_strchr(node->data, '-') == NULL)
		{
			info->nb_vertices++;
		}
		node = node->next;
	}
}

void			parse_end_start(t_info *info, char flag, t_nodes **node)
{
	unsigned int len;

	len = 0;
	while ((*node)->next->data[len] >= '0' && (*node)->next->data[len] <= '9')
		len++;
	if (!flag)
	{
		info->room_start = (char *)malloc(sizeof(char) * (len));
		ft_strncpy(info->room_start, (*node)->next->data, len);
	}
	else
	{
		info->room_end = (char *)malloc(sizeof(char) * (len));
		ft_strncpy(info->room_end, (*node)->next->data, len);
	}
	(*node) = (*node)->next;
}
