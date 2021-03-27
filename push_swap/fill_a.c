/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:03:21 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/27 18:03:51 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_a(t_stack **a, t_stack **b)
{
	if ((*b)->top && (*b)->top->val > (*a)->top->val)
	{
		while ((*b)->top && (*a)->end->val > (*b)->top->val)
			r_rotate('a', *a);
	}
	while ((*b)->top)
	{
		if ((*a)->end->val < (*a)->top->val && (*a)->end->val > (*b)->top->val)
			r_rotate('a', *a);
		else
			push('a', a, b);
	}
	while ((*a)->end->val < (*a)->top->val)
		r_rotate('a', *a);
}
