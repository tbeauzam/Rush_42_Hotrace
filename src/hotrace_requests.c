/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace_requests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 14:53:43 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/05/14 17:05:56 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static void		empty_buffer(t_data *d)
{
	d->buffer[d->buff_index] = '\0';
	write(1, d->buffer, d->buff_index);
	d->buff_index = 0;
}

static void		bufferize_result(t_data *d, char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (d->buff_index < PRNT_SIZE)
			d->buffer[d->buff_index] = s[i];
		else
		{
			empty_buffer(d);
			continue ;
		}
		i += 1;
		d->buff_index += 1;
	}
	d->buffer[d->buff_index] = '\0';
}

static void		is_in_it(t_data *d, t_dic *entry, char *s)
{
	while (entry)
	{
		if (entry->key_hash == d->hash)
			break ;
		entry = entry->next;
	}
	if (entry)
	{
		bufferize_result(d, entry->value);
		bufferize_result(d, "\n");
	}
	else
	{
		bufferize_result(d, s);
		bufferize_result(d, ": Not found.\n");
	}
}

static void		check_existence(t_data *d, t_dic **table, size_t *i, size_t j)
{
	size_t		backup;
	char		tmp[j + 1];

	backup = 0;
	tmp[j] = '\0';
	while (backup < j)
	{
		tmp[backup] = d->data[*i + backup];
		backup += 1;
	}
	*i += backup;
	d->hash = hash_djb(tmp);
	is_in_it(d, table[d->hash % HASH_SIZE], tmp);
}

void				treat_requests(t_data *d, t_dic **table)
{
	size_t	i;
	size_t	j;

	i = d->end_duo + 2;
	while (i < d->total)
	{
		j = 0;
		while (d->data[i + j] != '\n')
			j += 1;
		check_existence(d, table, &i, j);
		i += 1;
	}
	write(1, d->buffer, d->buff_index);
}
