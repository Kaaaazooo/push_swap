/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ilst_count_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:57:12 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/27 18:57:12 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ilst_count_sorted(uint8_t flag, t_ilst *lst)
{
	int64_t	val;
	int64_t	i;

	val = INT64_MIN;
	if (flag == D_ORDER)
		val = INT64_MAX;
	i = 0;
	while (lst)
	{
		if (flag == A_ORDER)
		{
			if (lst->val < val)
				return (i);
			val = lst->val;
		}
		else if (flag == D_ORDER)
		{
			if (lst->val > val)
				return (i);
			val = lst->val;
		}
		lst = lst->next;
		i++;
	}
	return (i);
}
