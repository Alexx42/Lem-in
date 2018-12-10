/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 04:04:37 by Alex              #+#    #+#             */
/*   Updated: 2018/12/10 14:00:03 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <stdio.h>
# include <libft.h>
# include <ft_printf.h>

# define SIZE 500000


typedef struct		s_hash
{
	char			*data;
	int				key;
}					t_hash;


t_hash		*hash_array[SIZE];
t_hash		*dummy_item;
t_hash		*item;

typedef struct		s_adj
{
	char 			*vertex;
	struct s_adj	*next;
}					t_adj;

typedef struct		s_graph
{
	char			nb_vertices;
	t_adj			**adj_list;
}					t_graph;

typedef struct		s_infos
{
	void			*room_start;
	void			*room_end;
	size_t			nb_ants;
}					t_infos;

void			lines_push_back(t_list **lst, char *str);
void			general_parsing(t_list *lst);
void			print_list(t_list *lst);
t_graph			*new_graph(int num_vertices);
void		add_edge(t_graph *graph, char *src, char *dst);
void			print_graph(t_graph *graph);
t_infos			*init_infos();
void			print_infos(t_infos *info);
int				hash_code(int key);
void			insert_data(int key, char *data);
int				search_item(char *data);
void			print_hash();

#endif