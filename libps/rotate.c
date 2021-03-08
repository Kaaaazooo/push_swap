/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:49:09 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/08 12:49:11 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	rotate(t_ilst *lst)
{
	t_ilst	*tmp;
	int64_t	val;

	if (lst == NULL || lst->next == NULL)
		return ;
	tmp = lst;
	val = lst->val;
	while (tmp->next)
	{
		tmp->val = tmp->next->val;
		tmp = tmp->next;
	}
	tmp->val = val;
}

void	rotate_s(t_ilst *a, t_ilst *b)
{
	rotate(a);
	rotate(b);
}

void	r_rotate(t_ilst *lst)
{
	t_ilst	*tmp;
	int64_t	val;
	int64_t	tmp_val;

	if (lst == NULL || lst->next == NULL)
		return ;
	tmp = lst;
	tmp_val = tmp->val;
	while (tmp->next)
	{
		val = tmp_val;
		tmp = tmp->next;
		tmp_val = tmp->val;
		tmp->val = val;
	}
	lst->val = tmp_val;
}

void	r_rotate_s(t_ilst *a, t_ilst *b)
{
	r_rotate(a);
	r_rotate(b);
}
