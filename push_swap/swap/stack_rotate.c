/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 10:52:16 by apalanic          #+#    #+#             */
/*   Updated: 2017/02/27 11:04:12 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_llist *node, t_bool r)
{
	t_stack	*last;
	t_stack	*scnd;

	last = node->a->prev;
	scnd = node->a->next;
	if (node->size_a > 1)
	{
		last->next = node->a;
		last->next->next = NULL;
		node->a = scnd;
		if (r && ++node->op_count)
			ft_printf((node->colour) ? (BLUE"ra\n"EOC) : ("ra\n"));
		if (r && node->verbose)
			stack_verbose(node);
	}
}

void	rotate_b(t_llist *node, t_bool r)
{
	t_stack	*last;
	t_stack *scnd;

	last = node->b->prev;
	scnd = node->b->next;
	if (node->size_b > 1)
	{
		last->next = node->b;
		last->next->next = NULL;
		node->b = scnd;
		if (r && ++node->op_count)
			ft_printf((node->colour) ? (BLUE"rb\n"EOC) : ("rb\n"));
		if (r && node->verbose)
			stack_verbose(node);
	}
}

void	rotate_both(t_llist *node)
{
	rotate_a(node, FALSE);
	rotate_b(node, FALSE);
	ft_printf((node->colour) ? (BLUE"rr\n"EOC) : ("rr\n"));
	node->op_count++;
	if (node->verbose)
		stack_verbose(node);
}
