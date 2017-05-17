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

#include "checker.h"

void	swap_a(t_env *node)
{
	int	tmp;

	if (node->size_a > 1)
	{
		tmp = node->a->data;
		node->a->data = node->a->next->data;
		node->a->next->data = tmp;
	}
}

void	swap_b(t_env *node)
{
	int	tmp;

	if (node->size_b > 1)
	{
		tmp = node->b->data;
		node->b->data = node->b->next->data;
		node->b->next->data = tmp;
	}
}

void	swap_both(t_env *node)
{
	if (node->size_a > 1)
		swap_a(node);
	if (node->size_b > 1)
		swap_b(node);
}
