/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:54:10 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/27 18:54:36 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int64_t	chunk_min(t_ilst *lst, int64_t chunk)
{
	int64_t	val;

	if (lst == NULL)
		return (0);
	val = INT64_MAX;
	while (lst)
	{
		if (lst->chunk == chunk && lst->val < val)
			val = lst->val;
		lst = lst->next;
	}
	return (val);
}

int64_t	chunk_max(t_ilst *lst, int64_t chunk)
{
	int64_t	val;

	if (lst == NULL)
		return (0);
	val = INT64_MIN;
	while (lst)
	{
		if (lst->chunk == chunk && lst->val > val)
			val = lst->val;
		lst = lst->next;
	}
	return (val);
}

int		chunk_size(t_ilst *lst, int64_t chunk)
{
	int	i;

	if (lst == NULL)
		return (0);
	i = 0;
	while (lst)
	{
		if (lst->chunk == chunk)
			++i;
		lst = lst->next;
	}
	return (i);
}

int64_t	biggest_chunk(t_ilst *a, t_ilst *b)
{
	int64_t	ret;

	ret = 0;
	while (a)
	{
		if (a->chunk > ret)
			ret = a->chunk;
		a = a->next;
	}
	while (b)
	{
		if (b->chunk > ret)
			ret = b->chunk;
		b = b->next;
	}
	return (ret);
}
