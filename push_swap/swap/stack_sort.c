#include "push_swap.h"

static void	fcking_sort(t_llist *node, int len, t_bool is_a)
{
	if ((node->size_a > 1 && node->size_b > 1) &&
		A_FIRST > A_SECOND && B_FIRST < B_SECOND)
		swap_both(node);
	if (is_a && node->size_a < 4)
		sort_short_stack(node, len, is_a);
	else if (!is_a && node->size_b < 4)
		sort_short_stack(node, len, is_a);
	else if (is_a && len == 2 && A_FIRST > A_SECOND)
		swap_a(node, TRUE);
	else if (!is_a && len == 2) 
	{
		if (B_FIRST < B_SECOND)
			swap_b(node, TRUE);
		push_a(node);
		push_a(node);
	}
	else if (is_a && len == 3)
		sort_three_a(node);
	else if (!is_a && len == 3)
		sort_three_b(node);

}

void		quick_sort_b(t_llist *node, int len, int i)
{
	int rotate;
	int push;
	int	med;
	static int call = 0;

	push = 0;
	rotate = 0;
	ft_printf("call B:%d len:%d\n", ++call, len);
	(len < 4) ? (fcking_sort(node, len, FALSE)) : (0);
	if (len < 4)
	{
		// ft_printf("tut");
		return ;
	}
	med = find_med(node, len, FALSE);
	while (i++ < len && is_lower_big_med(node->b, med, len - i, FALSE))
	{

		(B_FIRST) > med ? (push++) : (rotate++);
		(B_FIRST) > med ? push_a(node) : rotate_b(node, TRUE);
	}
	ft_printf("BBB1 sortA:%d sortB%d len:%d push:%d rot:%d A:%d B:%d i:%d med:%d\n",
	sorted(node, TRUE), sorted(node, FALSE), len, push , rotate, node->size_a, node->size_b, i, med);
	stack_verbose(node);
	quick_sort_a(node, push, 0);
	if (rotate > (node->size_b / 2) && node->size_b > 3 && len != node->size_b)
		while (rotate++ < node->size_b)
			rotate_b(node, TRUE);
	else if (node->size_b > 3)// && len != node->size_b)
		while (rotate--)
			rev_rotate_b(node, TRUE);
	quick_sort_b(node, len - push, 0);
}
void		quick_sort_a(t_llist *node, int len, int i)
{
	int rotate;
	int	push;
	int med;
	static int call = 0;
	push = 0;
	rotate = 0;
	ft_printf("call A:%d len:%d\n", ++call, len);
	(len < 4) ? (fcking_sort(node, len, TRUE)) : (0);
	if (len < 4)
		return ;
	med = find_med(node, len, TRUE);
	while (i++ < len && is_lower_big_med(node->a, med, len - i, TRUE))
	{
		(A_FIRST < med) ? (push++) : (rotate++);
		(A_FIRST < med) ? (push_b(node)) : rotate_a(node, TRUE);
	}
	ft_printf("AAA1 sortA:%d sortB%d len:%d push:%d rot:%d A:%d B:%d i:%d med:%d\n",
	sorted(node, TRUE), sorted(node, FALSE), len, push , rotate, node->size_a, node->size_b, i, med);
	if (rotate > (node->size_a / 2) && node->size_a > 3 && len != node->size_a)
		while (rotate++ < node->size_a)
			rotate_a(node, TRUE);
	else if (node->size_a > 3)// && len != node->size_a)
		while (rotate--)
			rev_rotate_a(node, TRUE);
	stack_verbose(node);
	quick_sort_a(node, len - push, 0);
	quick_sort_b(node, push, 0);
	// if (node->size_b < 4)
	// 	sort_short_stack(node, len, FALSE);
}
