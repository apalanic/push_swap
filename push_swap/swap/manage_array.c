/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:02:37 by apalanic          #+#    #+#             */
/*   Updated: 2017/02/28 18:00:45 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void		find_median(t_llist *node, int i, int j)
// {
// 	int		arr[node->size_a];
// 	int		swap;
// 	t_stack	*tmp;

// 	tmp = node->a;
// 	while (tmp)
// 	{
// 		arr[i++] = tmp->data;
// 		tmp = tmp->next;
// 	}
// //	find_min_position(node, arr, node->size_a);
// 	while (++j < node->size_a && (i = j) >= 0)
// 	{
// 		while (++i < node->size_a)
// 			if (arr[j] > arr[i])
// 			{
// 				swap = arr[j];
// 				arr[j] = arr[i];
// 				arr[i] = swap;
// 			}
// 	}
// 	node->median = arr[node->size_a / 2];
// }

// static void	median_position(t_llist *node)
// {
// 	t_stack	*tmp;
// 	int		i;

// 	i = 0;
// 	tmp = node->a;
// 	while (++i && tmp->next != NULL)
// 	{
// 		if (node->median == tmp->data)
// 		{
// 			node->med_pos = i;
// 			return ;
// 		}
// 		tmp = tmp->next;
// 	}
// }

// void		min_med_position(t_llist *node)
// {
// 	t_stack	*tmp;
// 	int		i;

// 	i = 0;
// 	tmp = node->a;
// 	node->min = node->a->data;
// 	median_position(node);
// 	while (tmp->next != NULL)
// 	{
// 		if (node->min > tmp->data)
// 			node->min = tmp->data;
// 		tmp = tmp->next;
// 	}
// 	tmp = node->a;
// 	while (++i && tmp->next != NULL)
// 	{
// 		if (node->min == tmp->data)
// 		{
// 			node->min_pos = i;
// 			return ;
// 		}
// 		tmp = tmp->next;
// 	}
// }

// int			find_med(t_llist *node, int len, t_bool is_stack_a, int j)
// {
// 	int		arr[len];
// 	int		swap;
// 	t_stack	*tmp;
// 	int		i;

// 	if ((i = 0) == 0 && is_stack_a)
// 		tmp = node->a;
// 	else
// 		tmp = node->b;
// 	while (tmp && i < len)
// 	{
// 		arr[i++] = tmp->data;
// 		tmp = tmp->next;
// 	}
// 	while (++j < len && (i = j) >= 0)
// 	{
// 		while (++i < len)
// 			if (arr[j] > arr[i])
// 			{
// 				swap = arr[j];
// 				arr[j] = arr[i];
// 				arr[i] = swap;
// 			}
// 	}
// 	return ((is_stack_a) ? (arr[len / 2]) : (arr[len / 2 - 1]));
//	return  (arr[len / 2]);
//}

int			find_med(t_llist *node, int len, t_bool is_a)
{
	int		arr[len];
	t_stack	*tmp;
	int		i;
	int		j;

	j = -1;
	i = -1;
	if (is_a)
		tmp = node->a;
	else
		tmp = node->b;
	while (++i < len)
	{
		arr[i] = tmp->data;
		tmp = tmp->next;
	}
//	ft_printf("***len%d i%d, is_a%d\n", len, i, is_a);
	while (++j < len - 1)
	{
		i = j;
		while (++i < len)
			if (arr[j] > arr[i])
				ft_swap(&arr[j], &arr[i]);
	}
	// i = -1;
	// while (++i < len)
	// 	ft_printf("*%d* %d\n", arr[i], arr[len / 2]);
	if (is_a)
		return (arr[len / 2]);
	else
		return ((len % 2) ? (arr[len / 2]) : (arr[len / 2 - 1]));
}

t_bool		is_lower_big_med(t_stack *stack, int med, int len, t_bool is_a)
{
	t_stack	*tmp;
	int		i;

	i = -1;
	tmp = stack;
	if (is_a)
	{
		while (tmp->next && ++i <= len)
		{
			if (tmp->data < med)
				return (TRUE);
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp->next && ++i <= len)
		{
			if (tmp->data > med)
				return (TRUE);
			tmp = tmp->next;
		}
	}
	return (FALSE);
}
