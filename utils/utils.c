/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:37:02 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/27 19:41:17 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

int	stack_operations(t_stack *a, t_stack *b, char *str)
{
	if (ft_strcmp("sa", str) == 0)
		swap(0, a->top);
	else if (ft_strcmp("sb", str) == 0)
		swap(0, b->top);
	else if (ft_strcmp("ss", str) == 0)
		swap_s(0, a->top, b->top);
	else if (ft_strcmp("pa", str) == 0)
		push(0, &a, &b);
	else if (ft_strcmp("pb", str) == 0)
		push(0, &b, &a);
	else if (ft_strcmp("ra", str) == 0)
		rotate(0, a);
	else if (ft_strcmp("rb", str) == 0)
		rotate(0, b);
	else if (ft_strcmp("rr", str) == 0)
		rotate_s(0, a, b);
	else if (ft_strcmp("rra", str) == 0)
		r_rotate(0, a);
	else if (ft_strcmp("rrb", str) == 0)
		r_rotate(0, b);
	else if (ft_strcmp("rrr", str) == 0)
		r_rotate_s(0, a, b);
	else
		return (-1);
	return (0);
}

int	check_ilsts(t_ilst *a, t_ilst *b)
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
