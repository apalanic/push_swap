/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:13:53 by apalanic          #+#    #+#             */
/*   Updated: 2017/03/06 19:31:45 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		update_mid(t_llist *node)
{
	node->mid = node->size_a / 2;
}

static void	get_min(t_llist *node, t_stack *tmp, int i)
{
	if (tmp->data < tmp->next->data && tmp->data <= node->min && tmp->next != NULL)
	{
		node->min_pos = i;
		node->min = tmp->data;
	}
	else if (tmp->data > tmp->next->data && tmp->next->data <= node->min && tmp->next != NULL)
	{
		node->min_pos = i + 1;
		node->min = tmp->next->data;
	}
}

void		search_min(t_llist *node)
{
	t_stack *tmp;
	int		i;

	i = 1;
	node->min = A_FIRST;
	if (node->a != NULL)
	{
		tmp = node->a;
		while (tmp->next != NULL)
		{
			get_min(node, tmp, i);
			tmp = tmp->next;
			i++;
		}
	}
}
