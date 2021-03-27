/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:06:15 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/27 19:53:56 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		update_chunk(t_stack **s, char c, t_chk_params *chk, int64_t **chunk)
{
	if (chk->size && chk->size != (*s)->size)
		while ((*s)->end->chunk == chk->id)
			r_rotate(c, *s);
	else
		chk->id = (*s)->top->chunk;
	chk->size = chunk_size((*s)->top, chk->id);
	chk->median = get_median((*s)->top, chk->size);
	++(**chunk);
	return (chk->size);
}

void	a_operations(t_stack **a, t_stack **b, t_chk_params *chk,
															int64_t *chunk)
{
	if (chk->size == 1)
		push('b', b, a);
	else if (chk->size == 2)
	{
		if ((*a)->top->val >= chunk_min((*a)->top, chk->id))
			swap('a', (*a)->top);
		if (!ilst_is_sorted(A_ORDER, (*a)->top))
			push('b', b, a);
	}
	else
	{
		if ((*a)->top->val < chk->median)
		{
			push('b', b, a);
			(*b)->top->chunk = *chunk;
		}
		else
			rotate('a', *a);
	}
}

void	mid_sort_a(int64_t *chunk, t_stack **a, t_stack **b)
{
	t_chk_params	chk;
	int				size;

	chk.id = (*a)->top->chunk;
	size = chunk_size((*a)->top, chk.id);
	chk.median = get_median((*a)->top, size);
	++(*chunk);
	while (!ilst_is_sorted(A_ORDER, (*a)->top) || !(*b)->top ||
		chunk_max((*b)->top, (*b)->top->chunk) >
		chunk_min((*a)->top, chk.id))
	{
		if ((*a)->size == 3 && get_min((*a)->top) > get_max((*b)->top))
			break ;
		chk.size = chunk_size((*a)->top, chk.id);
		if (chunk_min((*a)->top, chk.id) >= chk.median)
			size = update_chunk(a, 'a', &chk, &chunk);
		a_operations(a, b, &chk, chunk);
	}
}

void	b_operations(t_stack **a, t_stack **b, t_chk_params *chk,
													int64_t *chunk)
{
	if (chk->size == 1)
		push('a', a, b);
	else if (chk->size == 2)
	{
		if ((*b)->top->val == chunk_min((*b)->top, chk->id))
			swap('b', (*b)->top);
		if (!ilst_is_sorted(D_ORDER, (*b)->top))
			push('a', a, b);
	}
	else
	{
		if ((*b)->top->val > chk->median)
		{
			push('a', a, b);
			(*a)->top->chunk = *chunk;
		}
		else
			rotate('b', *b);
	}
}

void	mid_sort_b(int64_t *chunk, t_stack **a, t_stack **b)
{
	t_chk_params	chk;
	int				size;

	chk.id = (*b)->top->chunk;
	size = chunk_size((*b)->top, chk.id);
	chk.median = get_median((*b)->top, size);
	++(*chunk);
	while (!ilst_is_sorted(D_ORDER, (*b)->top) || !(*a)->top)
	{
		chk.size = chunk_size((*b)->top, chk.id);
		if (chunk_max((*b)->top, chk.id) <= chk.median)
			size = update_chunk(b, 'b', &chk, &chunk);
		b_operations(a, b, &chk, chunk);
	}
}
