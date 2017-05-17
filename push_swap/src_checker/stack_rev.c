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

#include "checker.h"

void	rev_rotate_a(t_env *node)
{
	t_stack	*last;
	t_stack *first;

	first = node->a;
	if (node->size_a > 1)
	{
		last = node->a->prev;
		last->prev->next = NULL;
		node->a->prev = last;
		node->a = last;
		last->next = first;
		last->prev = last->prev;
	}
}

void	rev_rotate_b(t_env *node)
{
	t_stack *last;
	t_stack *first;

	first = node->b;
	if (node->size_b > 1)
	{
		last = node->b->prev;
		last->prev->next = NULL;
		node->b->prev = last;
		node->b = last;
		last->next = first;
		last->prev = last->prev;
	}
}

void	rev_rotate_both(t_env *node)
{
	if (node->size_a > 1)
		rev_rotate_a(node);
	if (node->size_b > 1)
		rev_rotate_b(node);
}
