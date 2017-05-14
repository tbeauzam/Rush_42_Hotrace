/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:36:28 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/05/14 15:01:43 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static void		get_key(t_data *d, size_t *i, size_t j)
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
}

static void		get_value(t_data *d, size_t *i, size_t j)
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
	backup += 1;
	ft_memcpy(d->mem_value + d->index_mem_value, tmp, backup);
	d->new_dic->value = d->mem_value + d->index_mem_value;
	d->index_mem_value += backup;
}

void			hash_keys(t_data *d, t_dic **table)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < d->end_duo)
	{
		j = 0;
		while (d->data[i + j] != '\n')
			j += 1;
		get_key(d, &i, j);
		i += 1;
		put_in_table(d, table);
		j = 0;
		while (d->data[i + j] != '\n')
			j += 1;
		get_value(d, &i, j);
		i += 1;
	}
}
