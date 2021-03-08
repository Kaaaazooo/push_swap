#include "push_swap.h"

uint64_t	ft_abs(int64_t val)
{
	uint64_t	abs_val;

	if (val > 0)
		return ((uint64_t)val)
	abs_val = val * -1;
	return (abs_val);
}

int	ilst_count_sorted(t_ilst *lst)
{
	int64_t	val;
	int64_t	i;

	val = 0;
	i = 0;
	while (a)
	{
		if (a->val > val)
			val = a->val;
		else if (a->val < val)
			return (i);
		a = a->next;
		i++;
	}
	return (i);
}

int	ilst_is_sorted(uint8_t flag, t_ilst *lst)
{
	int64_t	val;
	int64_t	i;

	val = 0;
	if (flag == DESCENDING_ORDER)
		val = INT64_MAX;
	while (lst)
	{
		if (flag == ASCENDING_ORDER)
		{
			if (lst->val > val)
				val = lst->val;
			else if (lst->val < val)
				return (0);
		}
		if (flag == DESCENDING_ORDER)
		{
			if (lst->val < val)
				val = lst->val;
			else if (lst->val > val)
				return (0);
		}
		lst = lst->next;
	}
	return (1);
}

void	rotate_or_swap(t_stack **a, t_stack **b)
{
	if (ilst_count_sorted((*a)->top->next) > 1 &&
		(*a)->top->val > (*a)->top->next->next->val)
		rotate((*a)->top);
	else
		swap((*a)->top);
}

int	find_smallest(int64_t comp, int64_t a, int64_t b, int64_t c)
{
	int64_t	smallest;

	smallest = INT64_MAX;
	if (a < comp && a < smallest)
		smallest = a;
	if (b < comp && b < smallest)
		smallest = b;
	if (c < comp && c < smallest)
		smallest = c;
	return (smallest);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int64_t		smallest;

	if ((*b)->top == NULL)
		smallest = find_smallest(0,
			(*a)->top->val, (*a)->next->val, (*a)->end->val);
	else
		smallest = find_smallest((*b)->top->val,
			(*a)->top->val, (*a)->next->val, (*a)->end->val);
	if (top->val == smallest)
		push(b, a);
	else if (next->val == smallest)
		rotate_or_swap(a, b);
	else if (end->val == smallest)
		r_rotate((*a)->top);
}

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	char	*str;

	a = NULL;
	b = NULL;
	while (--ac > 0)
	{
		if (!is_digit_str(av[ac]))
			return (print_ret("Error\n", -1));
		stack_add_front(&a, ft_atoi(av[ac]));
	}
	if (a == NULL)
		return (print_ret("Error\n", -1));
	while (b->top && !ilst_is_sorted(ASCENDING_ORDER, a->top))
		sort_stack(&a, &b);
	str = NULL;
	free(str);
	str = NULL;
	return (stack_free_all(a) | stack_free_all(b));
}
