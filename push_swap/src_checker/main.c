/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 12:11:25 by apalanic          #+#    #+#             */
/*   Updated: 2017/03/20 15:58:17 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int ac, char **av)
{
	t_env	node;

	ft_bzero(&node, sizeof(t_env));
	if (ac > 1)
	{
		node.a = NULL;
		node.b = NULL;
		node.count = ac - 1;
		check_args(&node, &av[1]);
		if (read_comands(&node) && node.size_b == 0)
			ft_printf("\x1B[34mOK\x1B[0m\n");
		else
			ft_printf("\x1B[31mKO\x1B[0m\n");
		exit_program(&node, FALSE);
	}
	else
		exit_program(&node, TRUE);
	return (0);
}
