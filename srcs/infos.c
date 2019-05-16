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
	char			**split;

	split = ft_strsplit((*node)->next->data, ' ');
	if (!flag)
		info->room_start = ft_strdup(split[0]);
	else
		info->room_end = ft_strdup(split[0]);
	free(split[0]);
	free(split[1]);
	free(split[2]);
	free(split);
	(*node) = (*node)->next;
}
