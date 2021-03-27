/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ilst_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:59:29 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/27 18:02:02 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int64_t	get_min(t_ilst *lst)
{
	int64_t	val;

	if (lst == NULL)
		return (0);
	val = INT64_MAX;
	while (lst)
	{
		if (lst->val < val)
			val = lst->val;
		lst = lst->next;
	}
	return (val);
}

int64_t	get_max(t_ilst *lst)
{
	int64_t	val;

	if (lst == NULL)
		return (0);
	val = INT64_MIN;
	while (lst)
	{
		if (lst->val > val)
			val = lst->val;
		lst = lst->next;
	}
	return (val);
}
