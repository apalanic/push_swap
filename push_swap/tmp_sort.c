/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:24:21 by apalanic          #+#    #+#             */
/*   Updated: 2017/03/06 18:44:10 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_a(t_llist *node)
{
	while (node->size_b > 0)
		push_a(node);
}

void	move_to_b(t_llist *node)
{
	int	i;

	while (node->size_a > 3)
	{
		i = 0;
		search_min(node);
		while (i++ < node->min_pos - 1)
			rotate_a(node);
		push_b(node);
	}
	sort_short_stack_a(node);
}

void	check_special(t_llist *node)
{
	if (A_FIRST > A_SECOND && A_LAST > A_FIRST)
		swap_a(node);
	else if (A_LAST < A_BLAST && A_LAST > A_FIRST)
	{
		rev_rot_a(node);
		rev_rot_a(node);
		swap_a(node);
		rotate(node);
		rotate(node);
	}
	else if (A_FIRST > A_SECOND && A_LAST < A_FIRST)
		rotate(node);
	else if (A_LAST < A_BLAST && A_LAST < A_FIRST)
		reverse_a(node);
}

void	normal_sort(t_llist *node)
{
	check_special(node);
	if (sorted(node, TRUE))
		return ;
	move_to_b(node);
	move_to_a(node);
}
