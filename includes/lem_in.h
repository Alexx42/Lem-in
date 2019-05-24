/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 04:04:37 by Alex              #+#    #+#             */
/*   Updated: 2019/05/23 12:41:58 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <stdio.h>
# include <libft.h>
# include <ft_printf.h>

# define SIZE 500000

typedef struct		s_adj
{
	char 			*vertex;
	char			flag;
	struct s_adj	*next;
}					t_adj;


typedef struct		s_hash
{
	char			*data;
	int				key;
}					t_hash;

typedef struct 		s_info
{
	char			*room_start;
	char			*room_end;
	int				nb_ants;
	size_t			nb_vertices;
}					t_info;

typedef struct		s_val
{
	char			*content;
	struct s_val	*parent;
	struct s_val	*next;
}					t_val;

typedef struct		s_graph
{
	int				limit;
	char			verif;
	char			nb_vertices;
	t_val			**path;
	int				*nrip;
	int				count;
	int				**nb_ways;
	t_adj			**adj_list;
	int				*visited;
}					t_graph;


typedef struct		s_queue
{
	t_val			*front;
	t_val			*rear;
}					t_queue;

/*
** HASH
*/

t_hash				*hash_array[SIZE];
t_hash				*dummy_item;
t_hash				*item;

int					hash_code(int key);
void				insert_data(int key, char *data);
int					search_item(char *data);
void				create_hash(t_list *lst);

/*
** LISTS
*/

void				push_back(t_list **lst, char *str);
void				remove_idx_elements(t_adj **lst, char *str);

/*
** INFOS
*/

t_info				*parse_info(t_nodes *node);
void				parse_nb_vertices(t_nodes *node, t_info *info);


/*
** PARSING
*/

void				parsing_ants();
void				parse_end_start(t_info *info, char flag, t_nodes **node);



/*
** PRINTING FUNC
*/

void				print_info(t_info *info);
void				print_matrix(char **matrix, t_info *info);
void				print_hash();
void				print_graph(t_graph *graph);

/*
** QUEUE
*/

int					is_empty_queue(t_queue *queue);
t_queue				*create_queue();
void				enqueue(t_queue *queue, char *data, t_val *ok);
t_val				*dequeue(t_queue *queue);


/*
** GRAPH
*/

void				add_edge(t_graph *graph, char *src, char *dst);
t_graph				*new_graph(int num_vertices);
t_adj				*new_adj(char *val);

/*
** DISPATCHER
*/

int					dispatcher(t_graph *graph, t_info *info);

/*
** ERROR
*/
int					check_error(char *str);


#endif
