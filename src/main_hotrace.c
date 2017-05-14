/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hotrace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 00:57:39 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/05/13 16:58:18 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int			main(void)
{
	t_data	d;

	d.nb_duo = 0;
	d.end_duo = 0;
	read_stdin(&d);
//	ft_putstr(d.data);
	printf("nb lignes : %d\nDebut requetes : %d\n", d.nb_duo, d.end_duo);
	return (0);
}
