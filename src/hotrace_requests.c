/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace_requests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 14:53:43 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/05/14 15:01:52 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void				treat_requests(t_data *d, t_dic **table)
{
	size_t	i;
	size_t	j;

	i = d->end_duo;
	while (i < d->end_duo)
	{
		j = 0;
		while (d->data[i + j] != '\n')
			j += 1;
		i += 1;
	}
}
