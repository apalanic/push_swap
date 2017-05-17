/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:08:02 by apalanic          #+#    #+#             */
/*   Updated: 2017/02/22 15:57:52 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_stack_a(t_llist *node, int val)
{
	t_stack	*tmp;
	t_stack *new;

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
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		node->a->prev = new;
		new->prev = tmp;
	}
	node->size_a++;
}

void	add_stack_b(t_llist *node, int val)
{
	t_stack *tmp;
	t_stack *new;

	tmp = node->b;
	new = NULL;
	if ((new = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		exit_program(node, TRUE);
	new->prev = NULL;
	new->next = NULL;
	new->data = val;
	if (node->b == NULL)
		node->b = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		node->b->prev = new;
		new->prev = tmp;
	}
	node->size_b++;
}

void	del_stack_a(t_llist *node)
{
	t_stack	*tmp;
	t_stack *last;
	t_stack	*begin;

	if (node->size_a < 2)
	{
		free(node->a);
		node->a = NULL;
	}
	else if (node->a != NULL)
	{
		tmp = node->a->next;
		last = node->a->prev;
		begin = node->a;
		node->a = tmp;
		node->a->prev = last;
		free(begin);
	}
	node->size_a--;
}

void	del_stack_b(t_llist *node)
{
	t_stack	*tmp;
	t_stack *last;
	t_stack *begin;

	if (node->size_b < 2)
	{
		free(node->b);
		node->b = NULL;
	}
	else if (node->b != NULL)
	{
		tmp = node->b->next;
		last = node->b->prev;
		begin = node->b;
		node->b = tmp;
		node->b->prev = last;
		free(begin);
	}
	node->size_b--;
}

void	stack_verbose(t_llist *node)
{
	t_stack	*tmp;

	tmp = node->a;
	ft_printf("%sstack_A: %s", CYAN, EOC);
	while (tmp)
	{
		ft_printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	ft_printf("\n%sstack_B: %s", BLUE, EOC);
	tmp = node->b;
	while (tmp)
	{
		ft_printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
