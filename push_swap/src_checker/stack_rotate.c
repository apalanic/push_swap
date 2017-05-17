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

#include "checker.h"

void	rotate_a(t_env *node)
{
	t_stack *last;
	t_stack *second;

	last = node->a->prev;
	second = node->a->next;
	if (node->size_a > 1)
	{
		last->next = node->a;
		last->next->next = NULL;
		node->a = second;
	}
}

void	rotate_b(t_env *node)
{
	t_stack *last;
	t_stack *second;

	last = node->b->prev;
	second = node->b->next;
	if (node->size_b > 1)
	{
		last->next = node->b;
		last->next->next = NULL;
		node->b = second;
	}
}

void	rotate_both(t_env *node)
{
	if (node->size_a > 1)
		rotate_a(node);
	if (node->size_b > 1)
		rotate_b(node);
}
