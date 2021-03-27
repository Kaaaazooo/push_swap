/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:54:57 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/27 18:55:07 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	ft_printf("a :\n");
	if (a->top)
		print_ilst(a->top);
	write(1, "\n", 1);
	ft_printf("b :\n");
	if (b->top)
		print_ilst(b->top);
	write(1, "\n", 1);
}

int		sort_trinome(char c, t_stack *a)
{
	if (a->size != 3)
		return (0);
	while (!ilst_is_sorted(A_ORDER, a->top))
	{
		if (a->top->val > a->top->next->val && a->top->val < a->end->val)
			swap(c, a->top);
		else if (a->top->val > a->top->next->val && a->top->val > a->end->val)
			rotate(c, a);
		else
			r_rotate(c, a);
	}
	return (1);
}

void	push_swap(t_stack *a, t_stack *b)
{
	int64_t	chunk;

	chunk = 0;
	if (a->size == 3)
	{
		sort_trinome('a', a);
		return ;
	}
	while (!ilst_is_sorted(A_ORDER, a->top) || b->top)
	{
		chunk = biggest_chunk(a->top, b->top);
		if (a->top)
			mid_sort_a(&chunk, &a, &b);
		if (a->size == 3)
			sort_trinome('a', a);
		if (!ilst_is_sorted(A_ORDER, a->top) ||
			!ilst_is_sorted(D_ORDER, b->top))
			mid_sort_b(&chunk, &a, &b);
		if (ilst_is_sorted(A_ORDER, a->top) &&
			ilst_is_sorted(D_ORDER, b->top))
			fill_a(&a, &b);
	}
}

int		main(int ac, char **av)
{
	t_stack a;
	t_stack b;

	ft_bzero(&a, sizeof(t_stack));
	ft_bzero(&b, sizeof(t_stack));
	while (--ac > 0)
	{
		if (!is_digit_str(av[ac]))
			return (print_ret("Error\n", -1));
		stack_add_front(&a, ft_atoi(av[ac]));
	}
	if (check_duplicates(a.top, a.size))
		return (print_ret("Error\n", -1));
	if (a.top == NULL)
		return (print_ret("Error\n", -1));
	push_swap(&a, &b);
	return (ilst_free_all(a.top) | ilst_free_all(b.top));
}
