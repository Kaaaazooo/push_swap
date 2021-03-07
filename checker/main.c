#include "checker.h"

int	is_digit_str(char *str)
{
	int	i;

	if (str == NULL || *str == 0)
		return (0);
	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

int	print_ret(char *str, int ret)
{
	ft_printf("%s", str);
	return (ret);
}

int	stack_operations(t_stack **a, t_stack **b, char *str)
{
	if (ft_strcmp("sa", str) == 0)
		swap(*a);
	else if (ft_strcmp("sb", str) == 0)
		swap(*b);
	else if (ft_strcmp("ss", str) == 0)
		swap_s(*a, *b);
	else if (ft_strcmp("pa", str) == 0)
		push(a, b);
	else if (ft_strcmp("pb", str) == 0)
		push(b, a);
	else if (ft_strcmp("ra", str) == 0)
		rotate(*a);
	else if (ft_strcmp("rb", str) == 0)
		rotate(*b);
	else if (ft_strcmp("rr", str) == 0)
		rotate_s(*a, *b);
	else if (ft_strcmp("rra", str) == 0)
		r_rotate(*a);
	else if (ft_strcmp("rrb", str) == 0)
		r_rotate(*b);
	else if (ft_strcmp("rrr", str) == 0)
		r_rotate_s(*a, *b);
	else
		return (-1);
	return (0);
}

int	check_stacks(t_stack *a, t_stack *b)
{
	int64_t	val;

	if (b)
		return (print_ret("KO\n", -1));
	val = 0;
	while (a)
	{
		if (a->val > val)
			val = a->val;
		if (a->val < val)
			return (print_ret("KO\n", -2));
		a = a->next;
	}
	return (print_ret("OK\n", 0));
}

//	ft_printf("a :\n");
//	print_stack(a);
//	ft_printf("b :\n");
//	print_stack(b);
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
	str = NULL;
	while (get_next_line(0, &str) > 0)
	{
		if (stack_operations(&a, &b, str) < 0)
			return (print_ret("Error\n", -1));
		free(str);
		str = NULL;
	}
	free(str);
	check_stacks(a, b);
	str = NULL;
	return (stack_free_all(a) | stack_free_all(b));
}