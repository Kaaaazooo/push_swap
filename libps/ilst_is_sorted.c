/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ilst_is_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:57:16 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/27 18:57:17 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ilst_is_sorted(uint8_t flag, t_ilst *lst)
{
	int64_t	val;

	val = INT64_MIN;
	if (flag == D_ORDER)
		val = INT64_MAX;
	while (lst)
	{
		if (flag == A_ORDER)
		{
			if (lst->val > val)
				val = lst->val;
			else if (lst->val < val)
				return (0);
		}
		else if (flag == D_ORDER)
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
