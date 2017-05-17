/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:31:02 by apalanic          #+#    #+#             */
/*   Updated: 2017/02/22 17:30:34 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_4dup(t_llist *node, char **list)
{
	size_t	i;
	size_t	j;
	char	*arg;

	i = -1;
	while (list[++i] != NULL)
	{
		j = -1;
		arg = list[i];
		while (list[++j] != NULL)
		{
			if (j != i)
				if (!ft_strcmp(arg, list[j]))
					exit_program(node, TRUE);
		}
	}
}

static char	**parser(t_llist *node, char *stack, int *j)
{
	char	**new_stack;
	int		i;

	i = 0;
	new_stack = ft_strsplit(stack, ' ');
	while (new_stack[i] != NULL)
		i++;
	node->count = i;
	check_4dup(node, new_stack);
	(*j)--;
	return (new_stack);
}

static void	free_args(char **args)
{
	int	j;

	j = -1;
	while (args[++j] != NULL)
		free(args[j]);
	free(args);
}

void		check_args(t_llist *n, char **args)
{
	long long	tmp;
	size_t		i;
	int			j;

	j = 1;
	i = 0;
	n->count = (n->verbose || n->colour) ? (n->count - 1) : n->count;
	if (n->count != 1)
		check_4dup(n, args);
	else
		args = parser(n, args[0], &j);
	while (i < n->count)
	{
		if (!ft_isnumeric(args[i]))
			exit_program(n, TRUE);
		tmp = my_atoi(args[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			exit_program(n, TRUE);
		add_stack_a(n, (int)tmp);
		i++;
	}
	if (j == 0)
		free_args(args);
	push_swap(n);
	exit_program(n, FALSE);
}
