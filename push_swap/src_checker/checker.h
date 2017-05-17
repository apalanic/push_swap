/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 12:09:52 by apalanic          #+#    #+#             */
/*   Updated: 2017/02/27 11:20:32 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../libft/libft.h"

# define STDIN		0
# define EOF		-1
# define FALSE		0
# define TRUE		1

typedef int			t_bool;
typedef struct		s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_env
{
	t_stack			*a;
	t_stack			*b;
	int				count;
	int				size_a;
	int				size_b;
}					t_env;

int					ft_printf(const char *format, ...);
void				free_args(char **args);
t_bool				sorted(t_env *list);
void				check_4dup(t_env *list, char **args);
void				check_args(t_env *list, char **args);
void				exit_program(t_env *elem, t_bool is_error);
int					read_comands(t_env *list);
int					ft_isnumeric(const char *s);
long long			my_atoi(const char *s);
/*
** stack managment
*/
void				add_stack_a(t_env *list, int val);
void				add_stack_b(t_env *list, int val);
void				del_stack_a(t_env *list);
void				del_stack_b(t_env *list);
void				print_stack(t_env *list);
/*
** stack push front
*/
void				push_a(t_env *e);
void				push_b(t_env *e);
/*
** stack reverse
*/
void				rev_rotate_a(t_env *node);
void				rev_rotate_b(t_env *node);
void				rev_rotate_both(t_env *node);
/*
** stack rotate
*/
void				rotate_a(t_env *node);
void				rotate_b(t_env *node);
void				rotate_both(t_env *node);
/*
** stack swap
*/
void				swap_a(t_env *node);
void				swap_b(t_env *node);
void				swap_both(t_env *node);

#endif
