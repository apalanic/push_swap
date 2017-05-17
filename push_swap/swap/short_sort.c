/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:34:42 by apalanic          #+#    #+#             */
/*   Updated: 2017/03/01 15:11:31 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_b(t_llist *node)
{
	// if (B_FIRST > B_SECOND && B_FIRST > B_THIRD && B_SECOND > B_THIRD)
	// 	return ;
	// if (B_FIRST > B_THIRD && B_FIRST < B_SECOND && B_SECOND > B_THIRD)
	// {
	// 	swap_b(node, TRUE);
	// 	push_a(node);
	// 	push_a(node);
	// 	push_a(node);
	// 	return ;
	// }
	// if (B_FIRST < B_SECOND && B_FIRST < B_THIRD)
	// 	swap_b(node, TRUE);
	// push_a(node);
	// swap_b(node, TRUE);
	// push_a(node);
	// if (A_FIRST > A_SECOND)
	// 	swap_a(node, TRUE);
	// push_a(node);
	if (B_FIRST > B_SECOND && B_FIRST > B_THIRD && B_SECOND > B_THIRD)
		return ;
	if (B_FIRST > B_THIRD && B_FIRST < B_SECOND && B_SECOND > B_THIRD)
	{
		swap_b(node, TRUE);
		return ;
	}
	if (B_FIRST < B_SECOND && B_FIRST < B_THIRD)
		swap_b(node, TRUE);
	push_a(node);
	swap_b(node, TRUE);
	push_b(node);
	if (B_FIRST > B_THIRD && B_FIRST < B_SECOND && B_SECOND > B_THIRD)
		swap_b(node, TRUE);
}

void sort_three_a(t_llist *node)
{
	if (A_FIRST < A_SECOND && A_FIRST < A_THIRD && A_SECOND < A_THIRD)
		return ;
	if (A_FIRST > A_SECOND && A_FIRST < A_THIRD && A_SECOND < A_THIRD)
	{
		swap_a(node, TRUE);
		return ;
	}
	if (A_FIRST > A_SECOND && A_FIRST > A_THIRD)
		swap_a(node, TRUE);
	push_b(node);
	swap_a(node, TRUE);
	push_a(node);
	if (A_FIRST > A_SECOND && A_FIRST < A_THIRD && A_SECOND < A_THIRD)
		swap_a(node, TRUE);
}

void	sort_short_stack(t_llist *node, int len, t_bool is_a)
{
	if ((node->size_a > 1 && node->size_b > 1) &&
		A_FIRST > A_SECOND && B_FIRST < B_SECOND)
		swap_both(node);
	if (is_a && node->size_a == 3)
		sort_short_stack_a(node);
	else if (!is_a && node->size_b == 3)
		sort_short_stack_b(node);
	else if (is_a && len == 2 && A_FIRST > A_SECOND)
		swap_a(node, TRUE);
	else if (!is_a && len == 2 && B_FIRST < B_SECOND)
	{
		swap_b(node, TRUE);
		push_a(node);
		push_a(node);
	}
}

void	sort_short_stack_a(t_llist *node)
{
	if (sorted(node, TRUE))
		return ;
	if (A_FIRST > A_SECOND && A_FIRST > A_LAST)
		rotate_a(node, TRUE);
	else if ( A_SECOND > A_FIRST && A_SECOND > A_LAST)
		rev_rotate_a(node, TRUE);
	if (A_FIRST > A_SECOND && A_FIRST < A_LAST && A_SECOND < A_LAST)
		swap_a(node, TRUE);
}

void	sort_short_stack_b(t_llist *node)
{
	// if (sorted(node, FALSE))
	// 	return ;
	if (B_SECOND < B_FIRST && B_SECOND < B_LAST)
		rev_rotate_b(node, TRUE);
	else if (B_FIRST < B_SECOND && B_FIRST < B_LAST)
		rotate_b(node, TRUE);
	if (B_FIRST < B_SECOND && B_FIRST > B_LAST && B_SECOND > B_LAST)
		swap_b(node, TRUE);
	while (node->size_b)
		push_a(node);
}
