/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 11:34:40 by apalanic          #+#    #+#             */
/*   Updated: 2017/02/22 15:05:56 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool		sorted(t_llist *node, t_bool stack_a)
{
	t_stack	*tmp;

	if (node == NULL)
		return (FALSE);
	if (stack_a == TRUE)
		tmp = node->a;
	else
		tmp = node->b;
	while (tmp && stack_a)
	{
		if (tmp->next != NULL && tmp->data > tmp->next->data)
			return (FALSE);
		tmp = tmp->next;
	}
	while (tmp && !stack_a)
	{
		if (tmp->next != NULL && tmp->data < tmp->next->data)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

static void	free_stack(t_llist *node)
{
	t_stack *tmp;

	if (node->a)
	{
		tmp = node->a;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (tmp->prev)
				free(tmp->prev);
		}
		free(tmp);
	}
	if (node->b)
	{
		tmp = node->b;
		while (tmp->prev)
		{
			tmp = tmp->prev;
			node->b->prev = NULL;
			if (tmp->next)
				free(tmp->next);
		}
		free(tmp);
	}
}

void		exit_program(t_llist *node, t_bool err)
{
	if (err)
	{
		free_stack(node);
		ft_printf("{red}Error{eoc}");
		exit(1);
	}
	else
	{
		if (node->op_count && node->verbose)
			ft_printf("{blue}--\nTotal operations:{eoc} %d\n", node->op_count);
		free_stack(node);
		exit(0);
	}
}

t_bool		ft_isnumeric(const char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	if (*s == '\0')
		return (FALSE);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (FALSE);
		s++;
	}
	return (TRUE);
}

long long	my_atoi(const char *s)
{
	long long res;
	long long sign;

	res = 0;
	sign = 1;
	while ((9 <= *s && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
		if (*(s + 1) >= '0' && *(s + 1) <= '9' && *(s + 1) != '\0')
		{
			sign = 44 - *s;
			s++;
		}
	while (*s >= '0' && *s <= '9' && *s != '\0')
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return (res * sign);
}
