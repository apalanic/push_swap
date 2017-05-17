/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 12:28:04 by apalanic          #+#    #+#             */
/*   Updated: 2017/02/27 09:31:24 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		free_args(char **args)
{
	int	j;

	j = -1;
	while (args[++j] != NULL)
		free(args[j]);
	free(args);
}

t_bool		sorted(t_env *list)
{
	t_stack	*tmp;

	tmp = list->a;
	while (tmp)
	{
		if (tmp->next != NULL && tmp->data > tmp->next->data)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

void		check_4dup(t_env *list, char **args)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	while (args[++i] != NULL)
	{
		j = -1;
		tmp = args[i];
		while (args[++j] != NULL)
		{
			if (j != i)
				if (!ft_strcmp(tmp, args[j]))
					exit_program(list, TRUE);
		}
	}
}

static char	**parse_text(t_env *list, char *stack)
{
	char	**empty;
	size_t	i;

	i = 0;
	empty = ft_strsplit(stack, ' ');
	while (empty[i] != NULL)
		i++;
	list->count = i;
	check_4dup(list, empty);
	return (empty);
}

void		check_args(t_env *list, char **args)
{
	int			i;
	long long	tmp;
	int			j;

	j = 1;
	i = 0;
	if (list->count != 1)
		check_4dup(list, args);
	else
	{
		args = parse_text(list, args[0]);
		j--;
	}
	while (i < list->count)
	{
		if (!ft_isnumeric(args[i]))
			exit_program(list, TRUE);
		tmp = my_atoi(args[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			exit_program(list, TRUE);
		add_stack_a(list, (int)tmp);
		i++;
	}
	if (j == 0)
		free_args(args);
}
