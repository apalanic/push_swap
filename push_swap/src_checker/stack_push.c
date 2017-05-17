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

#include "checker.h"

static void	stack_push_front_a(t_env *node, int val)
{
	t_stack *tmp;
	t_stack *new;

	tmp = node->a;
	new = NULL;
	if ((new = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		exit_program(node, TRUE);
	new->next = NULL;
	new->prev = NULL;
	new->data = val;
	if (node->a != NULL)
	{
		node->a = new;
		new->next = tmp;
		tmp->prev = node->a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->prev = tmp;
	}
	else
		node->a = new;
	node->size_a++;
}

static void	stack_push_front_b(t_env *node, int val)
{
	t_stack *tmp;
	t_stack *new;

	tmp = node->b;
	new = NULL;
	if ((new = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		exit_program(node, TRUE);
	new->next = NULL;
	new->prev = NULL;
	new->data = val;
	if (node->b != NULL)
	{
		node->b = new;
		new->next = tmp;
		tmp->prev = node->b;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->prev = tmp;
	}
	else
		node->b = new;
	node->size_b++;
}

void		push_a(t_env *node)
{
	if (node->size_b > 0 && node->b != NULL)
	{
		stack_push_front_a(node, node->b->data);
		del_stack_b(node);
	}
}

void		push_b(t_env *node)
{
	if (node->size_a > 0 && node->a != NULL)
	{
		stack_push_front_b(node, node->a->data);
		del_stack_a(node);
	}
}
