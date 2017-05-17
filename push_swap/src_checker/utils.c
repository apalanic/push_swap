/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:07:17 by apalanic          #+#    #+#             */
/*   Updated: 2017/02/25 16:18:46 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	free_stack(t_env *elem)
{
	t_stack	*tmp;

	if (elem->a)
	{
		tmp = elem->a;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			if (tmp->prev)
				free(tmp->prev);
		}
		free(tmp);
	}
	if (elem->b)
	{
		tmp = elem->b;
		while (tmp->prev != NULL)
		{
			tmp = tmp->prev;
			elem->b->prev = NULL;
			if (tmp->next)
				free(tmp->next);
		}
		free(tmp);
	}
}

void		exit_program(t_env *elem, t_bool is_error)
{
	free_stack(elem);
	if (is_error)
	{
		ft_printf("\x1B[31mError\x1B[0m\n");
		exit(1);
	}
	exit(0);
}

int			ft_isnumeric(const char *s)
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
