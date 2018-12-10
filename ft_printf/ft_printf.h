/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:32:44 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/14 18:29:44 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

# define PW7 128
# define PW6 64
# define PW5 32
# define PW4 16
# define PW3 8
# define PW2 4
# define PW1 2
# define PW0 1

typedef struct		s_params
{
	unsigned char	flags;
	unsigned char	lmod;
	unsigned char	type;
}					t_params;

typedef struct		s_book
{
	size_t			width;
	size_t			prec;
}					t_book;

int					ft_printf(const char *fmt, ...);

char				*parsing(char *fmt, t_params *params, t_book *book);

int					init_structs(t_params **params, t_book **book, int reset);

void				set_params(unsigned char bitnb, unsigned char *c);
void				unset_params(unsigned char bitnb, unsigned char *c);
int					param_is_on(unsigned char bitnb, unsigned char *c);

void				print_conv(t_params *params, t_book *book,
								va_list ap, int *count);

void				putchar_printf(char c, int *count);
void				putstr_printf(char *s, int *count);
void				print_char(t_params *params, t_book *book,
								va_list ap, int *count);
void				print_str(t_params *params, t_book *book,
								va_list ap, int *count);

void				print_special_str(t_params *params, t_book *book,
								va_list ap, int *count);

void				print_signed(long long nb, int *count);
void				print_unsigned(unsigned long long nb,
					unsigned long long base, t_params *params, int *count);
long long			lmod_signed(t_params *params, va_list ap);
unsigned long long	lmod_unsigned(t_params *params, va_list ap);

void				set_unsigned_len_and_base(t_params *params,
					unsigned long long nb, size_t *len, int *base);
int					print_or_nah(t_params *params, t_book *book);

void				padding_left(t_params *params, t_book *book,
								size_t len, int *count);
void				padding_right(t_params *params, t_book *book,
								size_t len, int *count);

size_t				signed_nb_size(long long nb);
size_t				unsigned_nb_size(unsigned long long nb,
									unsigned long long base);

int					ft_atoi_printf(const char *str);
int					ft_isdigit_printf(int c);
size_t				ft_strlen_printf(const char *s);
char				*strdup_wchar(wchar_t *s1, size_t *len);
char				*ft_strdup_printf(const char *s1);

#endif
