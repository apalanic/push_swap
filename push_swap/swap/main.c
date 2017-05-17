/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 12:11:25 by apalanic          #+#    #+#             */
/*   Updated: 2017/03/02 15:30:53 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(t_llist *node)
{
	if (!sorted(node, TRUE))
		quick_sort_a(node, node->size_a, 0);
	else if (node->verbose)
	{
		stack_verbose(node);
		ft_printf("Stack is sorted !\n");
	}
	// if (!sorted(node, TRUE))
	//	exit_program(node, FALSE);
	// else
	// 	exit_program(node, TRUE);
}
 
static void	usage(void)
{
	ft_printf("usage: [option] [NB1 NB2 ...]\n\n");
	ft_printf("\t-v\t\tshow stack's status after each operation\n");
	ft_printf("\t-c\t\tshow all operations in colours\n");
	ft_printf("\t--help\tshow this message\n");
}

int			main(int ac, char **av)
{
	t_llist	node;

	ft_bzero(&node, sizeof(t_llist));
	if (ac > 1)
	{
		node.a = NULL;
		node.b = NULL;
		node.count = ac - 1;
		if ((!ft_strcmp(av[1], "-v") || !ft_strcmp(av[1], "-c")) && ac > 2)
		{
			(!ft_strcmp(av[1], "-v")) ? (node.verbose = TRUE)
			: (node.colour = TRUE);
			check_args(&node, &av[2]);
		}
		else if (!ft_strcmp(av[1], "--help") || !ft_strcmp(av[1], "-v")
				|| !ft_strcmp(av[1], "-c"))
			usage();
		else
			check_args(&node, &av[1]);
	}
	else
		usage();
	while (1);
	return (0);
}
