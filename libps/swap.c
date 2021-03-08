/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:49:26 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/08 12:49:27 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include "stdio.h"

void	swap(t_ilst *lst)
{
	int64_t	val;

	if (lst->next == NULL)
		return ;
	val = lst->next->val;
	lst->next->val = lst->val;
	lst->val = val;
}

void	swap_s(t_ilst *a, t_ilst *b)
{
	swap(a);
	swap(b);
}
