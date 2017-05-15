/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 00:50:08 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/05/14 19:16:39 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

# define BUFF_SIZE	300000
# define HASH_SIZE	2048
# define HASH_CONST	5385
# define PRNT_SIZE	65535

typedef struct		s_dic
{
	unsigned long	key_hash;
	char			*value;
	struct s_dic	*next;
	struct s_dic	*last;
}					t_dic;

typedef struct		s_list
{
	char			*data;
	struct s_list	*next;
}					t_list;

typedef struct		s_data
{
	t_dic			*mem_dic;
	t_dic			*new_dic;
	t_list			*head;
	size_t			nb_duo;
	size_t			end_duo;
	size_t			value_size;
	size_t			index_mem_dic;
	size_t			index_mem_value;
	size_t			total;
	size_t			buff_index;
	char			*mem_value;
	char			*data;
	char			*value;
	char			buffer[PRNT_SIZE + 1];
	unsigned long	hash;
}					t_data;

unsigned int		ft_strlen(char *s);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, void const *src, size_t n);
char				*ft_strdup(char const *s1);
void				ft_strdel(char **as);

char				*read_stdin(t_data *d);
void				hash_keys(t_data *d, t_dic **table);
unsigned long		hash_djb(char *s);
void				put_in_table(t_data *d, t_dic **table);
void				treat_requests(t_data *d, t_dic **table);

#endif
