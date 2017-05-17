/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:10:10 by apalanic          #+#    #+#             */
/*   Updated: 2017/02/27 11:17:33 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_llist *node, t_bool r)
{
	int	tmp;

	if (node->size_a > 1)
	{
		tmp = node->a->data;
		node->a->data = node->a->next->data;
		node->a->next->data = tmp;
		if (r && ++node->op_count)
			ft_printf((node->colour) ? (YELLOW"sa\n"EOC) : ("sa\n"));
		if (r && node->verbose)
			stack_verbose(node);
	}
}

void	swap_b(t_llist *node, t_bool r)
{
	int	tmp;

	if (node->size_b > 1)
	{
		tmp = node->b->data;
		node->b->data = node->b->next->data;
		node->b->next->data = tmp;
		if (r && ++node->op_count)
			ft_printf((node->colour) ? (YELLOW"sb\n"EOC) : ("sb\n"));
		if (r && node->verbose)
			stack_verbose(node);
	}
}

void	swap_both(t_llist *node)
{
	swap_a(node, FALSE);
	swap_b(node, FALSE);
	ft_printf((node->colour) ? (YELLOW"ss\n"EOC) : ("ss\n"));
	node->op_count++;
	if (node->verbose)
		stack_verbose(node);
}
