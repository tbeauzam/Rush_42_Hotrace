/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 00:50:08 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/05/13 16:01:42 by tbeauzam         ###   ########.fr       */
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

# define BUFF_SIZE 200000

typedef struct		s_list
{
	char			*data;
	struct s_list	*next;
}					t_list;

typedef struct		s_data
{
	char			*data;
	int				nb_duo;
	int				end_duo;
}					t_data;

unsigned int		ft_strlen(char *s);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, void const *src, size_t n);
void				*ft_memmove(void *dst, void const *src, size_t len);
char				*ft_strchr(char const *s, int c);
char				*ft_strdup(char const *s1);
void				ft_strdel(char **as);
void				ft_putstr(char *s);
//char				**ft_strsplit(char *s, char c);

char				*read_stdin(t_data *d);

#endif
