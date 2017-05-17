/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:21:45 by apalanic          #+#    #+#             */
/*   Updated: 2017/02/27 10:06:32 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	add_stack_a(t_env *list, int val)
{
	t_stack	*tmp;
	t_stack *new;

	tmp = list->a;
	new = NULL;
	if ((new = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		exit_program(list, TRUE);
	new->next = NULL;
	new->prev = NULL;
	new->data = val;
	if (list->a != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		list->a->prev = new;
		new->prev = tmp;
	}
	else
		list->a = new;
	list->size_a++;
}

void	add_stack_b(t_env *list, int val)
{
	t_stack *new;
	t_stack *tmp;

	tmp = list->b;
	new = NULL;
	if ((new = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		exit_program(list, TRUE);
	new->next = NULL;
	new->prev = NULL;
	new->data = val;
	if (list->b != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		list->b->prev = new;
		new->prev = tmp;
	}
	else
		list->b = new;
	list->size_b++;
}

void	del_stack_a(t_env *list)
{
	t_stack	*next;
	t_stack *prev;
	t_stack *curr;

	if (list->size_a < 2)
	{
		free(list->a);
		list->a = NULL;
	}
	else
	{
		if (list->a != NULL)
		{
			next = list->a->next;
			prev = list->a->prev;
			curr = list->a;
			list->a = next;
			list->a->prev = prev;
			free(curr);
		}
	}
	list->size_a--;
}

void	del_stack_b(t_env *list)
{
	t_stack *next;
	t_stack *prev;
	t_stack *curr;

	if (list->size_b < 2)
	{
		free(list->b);
		list->b = NULL;
	}
	else
	{
		if (list->b != NULL)
		{
			next = list->b->next;
			prev = list->b->prev;
			curr = list->b;
			list->b = next;
			list->b->prev = prev;
			free(curr);
		}
	}
	list->size_b--;
}
