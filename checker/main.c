/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:32:48 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/08 12:36:41 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**	ft_printf("a :\n");
**	print_ilst(a.top);
**	write(1, "\n", 1);
**	ft_printf("b :\n");
**	print_ilst(b.top);
**	write(1, "\n", 1);
*/

int	main(int ac, char **av)
{
	t_stack a;
	t_stack b;
	char	*str;

	ft_bzero(&a, sizeof(t_stack));
	ft_bzero(&b, sizeof(t_stack));
	while (--ac > 0)
	{
		if (!is_digit_str(av[ac]))
			return (print_ret("Error\n", -1));
		stack_add_front(&a, ft_atoi(av[ac]));
	}
	if (a.top == NULL || check_duplicates(a.top, a.size))
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
	check_ilsts(a.top, b.top);
	return (ilst_free_all(a.top) | ilst_free_all(b.top));
}
