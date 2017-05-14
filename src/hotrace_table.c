/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 01:00:45 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/05/14 14:52:17 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static void		the_great_modulo(t_data *d, t_dic **table, t_dic *new, int mod)
{
	t_dic		*tmp;

	tmp = table[mod];
	if (tmp)
	{
		if (tmp->last)
			tmp = tmp->last;
		tmp->next = d->new_dic;
		table[mod]->last = d->new_dic;
	}
	else
		table[mod] = new;
}

void			put_in_table(t_data *d, t_dic **table)
{
	d->new_dic = &d->mem_dic[d->index_mem_dic];
	d->index_mem_dic += 1;
	d->new_dic->key_hash = d->hash;
	d->new_dic->value = NULL;
	d->new_dic->next = NULL;
	d->new_dic->last = NULL;
	the_great_modulo(d, table, d->new_dic, d->new_dic->key_hash % HASH_SIZE);
}
