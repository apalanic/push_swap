/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 15:09:56 by apalanic          #+#    #+#             */
/*   Updated: 2017/02/27 09:31:39 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	exec_swap(t_env *list, char *command)
{
	if (!ft_strcmp(command, "sa"))
		swap_a(list);
	else if (!ft_strcmp(command, "sb"))
		swap_b(list);
	else if (!ft_strcmp(command, "ss"))
		swap_both(list);
}

int			exec_comands(t_env *list, char *command)
{
	if (!ft_strcmp(command, "sa") || !ft_strcmp(command, "sb") ||
				!ft_strcmp(command, "ss"))
		exec_swap(list, command);
	else if (!ft_strcmp(command, "pa"))
		push_a(list);
	else if (!ft_strcmp(command, "pb"))
		push_b(list);
	else if (!ft_strcmp(command, "ra"))
		rotate_a(list);
	else if (!ft_strcmp(command, "rb"))
		rotate_b(list);
	else if (!ft_strcmp(command, "rr"))
		rotate_both(list);
	else if (!ft_strcmp(command, "rra"))
		rev_rotate_a(list);
	else if (!ft_strcmp(command, "rrb"))
		rev_rotate_b(list);
	else if (!ft_strcmp(command, "rrr"))
		rev_rotate_both(list);
	else
		return (1);
	return (0);
}

int			read_comands(t_env *list)
{
	char *line;

	while (get_next_line(STDIN, &line) > 0)
	{
		if (exec_comands(list, line))
		{
			ft_bzero(line, 16);
			free(line);
			exit_program(list, TRUE);
		}
		free(line);
	}
	free(line);
	return (sorted(list));
}
