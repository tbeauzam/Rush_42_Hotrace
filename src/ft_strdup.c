/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:13:14 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/05/13 01:24:46 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*ft_strdup(char const *s1)
{
	int		i;
	int		len;
	char	*dup;

	len = (ft_strlen((char *)s1));
	dup = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = s1[i];
		i += 1;
	}
	dup[i] = '\0';
	return (dup);
}
