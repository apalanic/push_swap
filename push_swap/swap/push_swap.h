/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:25:00 by apalanic          #+#    #+#             */
/*   Updated: 2017/02/22 17:30:25 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "../libft/libft.h"

# define A_FIRST	node->a->data
# define B_FIRST	node->b->data
# define A_SECOND	node->a->next->data
# define B_SECOND	node->b->next->data
# define A_THIRD	node->a->next->next->data
# define B_THIRD	node->b->next->next->data
# define A_LAST		node->a->prev->data
# define B_LAST		node->b->prev->data
# define A_BLAST	node->a->prev->prev->data
# define B_BLAST	node->b->prev->prev->data

# define TRUE		1
# define FALSE		0
# define STACK_A	1
# define STACK_B	0

# define RED		"\x1B[31m"
# define GREEN		"\x1B[32m"
# define YELLOW		"\x1B[33m"
# define BLUE		"\x1B[34m"
# define MAGENTA	"\x1B[35m"
# define CYAN		"\x1B[36m"
# define WHITE		"\x1B[37m"
# define EOC		"\x1B[0m"

typedef int			t_bool;

typedef struct		s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				data;
}					t_stack;

typedef struct		s_llist
{
	t_stack			*a;
	t_stack			*b;
	int				size_a;
	int				size_b;
	size_t			count;
	t_bool			verbose;
	t_bool			colour;
	size_t			op_count;
}					t_llist;


/*
** all other functions easy to anderstand
*/
void				push_swap(t_llist *node);
/*
** exit program with free stack **utils.c
*/
void				exit_program(t_llist *node, t_bool err);
/*
** check if stack is sorted (TRUE == a, FALSE == b) **utils.c
*/
t_bool				sorted(t_llist *node, t_bool stack_a);
/*
** check if args is all valid numeric **utils.c
*/
t_bool				ft_isnumeric(const char *s);
/*
** atoi changed to long long **utils.c
*/
long long			my_atoi(const char *s);
/*
** check if all args are valid **check.c
*/
void				check_args(t_llist *n, char **args);
/*
** stack managment functions **stack_manager.c
*/
void				add_stack_a(t_llist *node, int val);
void				add_stack_b(t_llist *node, int val);
void				del_stack_a(t_llist *node);
void				del_stack_b(t_llist *node);
/*
** deteils for -v flag 		**stack_manager.c
*/
void				stack_verbose(t_llist *node);
/*
** stack push operations --pa pb--  **stack_push.c
*/
void				push_a(t_llist *node);
void				push_b(t_llist *node);
/*
** stack reverse rotates --rra rrb rrr-- **stack_reverse.c
*/
void				rev_rotate_b(t_llist *node, t_bool r);
void				rev_rotate_a(t_llist *node, t_bool r);
void				rev_rotate_both(t_llist *node);
/*
** stack rotate --ra rb rr-- **stack_rotate.c
*/
void				rotate_a(t_llist *node, t_bool r);
void				rotate_b(t_llist *node, t_bool r);
void				rotate_both(t_llist *node);
/*
** stack swap --sa sb ss-- **stack_swap.c
*/
void				swap_a(t_llist *node, t_bool r);
void				swap_b(t_llist *node, t_bool r);
void				swap_both(t_llist *node);
/*
** sorting functions
*/
void				sort_short_stack(t_llist *node, int len, t_bool is_a);
void				sort_stack_a(t_llist *node);
void				quick_sort_a(t_llist *node, int len, int i);
void				sort_short_stack_a(t_llist *node);
void				sort_short_stack_b(t_llist *node);
void 				sort_three_a(t_llist *node);
void 				sort_three_b(t_llist *node);
/*
** others
*/
int					find_med(t_llist *node, int len, t_bool is_stack_a);
t_bool				is_lower_big_med(t_stack *stack, int med, int len, t_bool is_a);

#endif
