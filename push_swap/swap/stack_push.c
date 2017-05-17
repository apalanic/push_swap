/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 10:09:02 by apalanic          #+#    #+#             */
/*   Updated: 2017/02/27 10:35:34 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_front_a(t_llist *node, int val)
{
	t_stack	*tmp;
	t_stack	*new;

	tmp = node->a;
	new = NULL;
	if ((new = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		exit_program(node, TRUE);
	new->next = NULL;
	new->prev = NULL;
	new->data = val;
	if (node->a == NULL)
		node->a = new;
	else
	{
		node->a = new;
		new->next = tmp;
		tmp->prev = node->a;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
	}
	node->size_a++;
}

static void	push_front_b(t_llist *node, int val)
{
	t_stack	*tmp;
	t_stack	*new;

	tmp = node->b;
	new = NULL;
	if ((new = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		exit_program(node, TRUE);
	new->next = NULL;
	new->prev = NULL;
	new->data = val;
	if (node->b == NULL)
		node->b = new;
	else
	{
		node->b = new;
		new->next = tmp;
		tmp->prev = node->b;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
	}
	node->size_b++;
}

void		push_a(t_llist *node)
{
	if (node->size_b && node->b != NULL)
	{
		push_front_a(node, node->b->data);
		del_stack_b(node);
		ft_printf((node->colour) ? (GREEN"pa\n"EOC) : ("pa\n"));
		if (node->verbose)
			stack_verbose(node);
		node->op_count++;
	}
}

void		push_b(t_llist *node)
{
	if (node->size_a && node->a != NULL)
	{
		push_front_b(node, node->a->data);
		del_stack_a(node);
		ft_printf((node->colour) ? (GREEN"pb\n"EOC) : ("pb\n"));
		if (node->verbose)
			stack_verbose(node);
		node->op_count++;
	}
}
