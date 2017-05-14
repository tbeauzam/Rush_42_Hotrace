/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace_get_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 13:23:31 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/05/13 16:30:12 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_list			*create_elem(t_list *l, char *s)
{
	if (!(l = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	l->data = ft_strdup(s);
	l->next = NULL;
	return (l);
}

void			add_to_head(t_list **head, char *s)
{
	t_list		*new;
	t_list		*tmp;

	if ((new = create_elem(NULL, s)))
	{
		tmp = *head;
		if (tmp)
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		else
		{
			tmp = new;
			*head = tmp;
		}
	}
}

void			put_into_one_buffer(t_data *d, char *s, t_list *head)
{
	t_list		*tmp;
	int			i;
	int			j;

	i = 0;
	tmp = head;
	while (tmp)
	{
		j = 0;
		while (tmp->data[j])
		{
			if (tmp->data[j] == '\n')
			{
				if (!d->end_duo)
					d->nb_duo += 1;
				if (tmp->data[j + 1] == '\n')
					d->end_duo = i;
			}
			s[i] = tmp->data[j];
			j += 1;
			i += 1;
		}
		tmp = tmp->next;
	}
}

char			*read_stdin(t_data *d)
{
	int			ret;
	int			total;
	char		buf[BUFF_SIZE + 1];
	t_list		*head;

	head = NULL;
	total = 0;
	while ((ret = read(0, buf, BUFF_SIZE)) != 0)
	{
		buf[ret] = '\0';
		add_to_head(&head, buf);
		total += ret;
	}
	d->data = NULL;
	if (!(d->data = (char *)malloc(sizeof(char) * (total + 1))))
		return (NULL);
	d->data[total] = '\0';
	put_into_one_buffer(d, d->data, head);
	return ("");
}
