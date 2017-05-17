/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 10:36:21 by apalanic          #+#    #+#             */
/*   Updated: 2017/02/27 10:51:53 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_llist *node, t_bool r)
{
	t_stack *last;
	t_stack *frst;

	last = NULL;
	frst = node->a;
	if (node->size_a > 1)
	{
		last = node->a->prev;
		last->prev->next = NULL;
		node->a->prev = last;
		node->a = last;
		last->next = frst;
		last->prev = last->prev;
		if (r && ++node->op_count)
			ft_printf((node->colour) ? (MAGENTA"rra\n"EOC) : ("rra\n"));
		if (node->verbose && r)
			stack_verbose(node);
	}
}

void	rev_rotate_b(t_llist *node, t_bool r)
{
	t_stack	*last;
	t_stack *frst;

	last = NULL;
	frst = node->b;
	if (node->size_b > 1)
	{
		last = node->b->prev;
		last->prev->next = NULL;
		node->b->prev = last;
		node->b = last;
		last->next = frst;
		last->prev = last->prev;
		if (r && ++node->op_count)
			ft_printf((node->colour) ? (CYAN"rrb\n"EOC) : ("rrb\n"));
		if (node->verbose && r)
			stack_verbose(node);
	}
}

void	rev_rotate_both(t_llist *node)
{
	rev_rotate_a(node, FALSE);
	rev_rotate_b(node, FALSE);
	ft_printf((node->colour) ? (WHITE"rrr\n"EOC) : ("rrr\n"));
	node->op_count++;
	if (node->verbose)
		stack_verbose(node);
}
