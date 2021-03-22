/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:49:09 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/22 19:16:47 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	rotate(char c, t_ilst **lst)
{
	t_ilst	*tmp;
	t_ilst	*tmp1;
	int64_t	val;
	char	str[3];

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	tmp = *lst;
	while ((*lst)->next)
	{
		tmp1 = *lst;
		*lst = (*lst)->next;
	}
	(*lst)->next = tmp;
	(*lst) = tmp1;
	(*lst)->next = NULL;
	if (c)
	{
		str[0] = 'r';
		str[1] = c;
		str[2] = '\n';
		write(1, str, 3);
	}
}

void	rotate_s(char c, t_ilst *a, t_ilst *b)
{
	rotate(0, a);
	rotate(0, b);
	if (c)
		write(1, "rr\n", 3);
}

void	r_rotate(char c, t_ilst *lst)
{
	t_ilst	*tmp;
	int64_t	val;
	int64_t	tmp_val;
	char	str[4];

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
	if (c)
	{
		str[0] = 'r';
		str[1] = 'r';
		str[2] = c;
		str[3] = '\n';
		write(1, str, 4);
	}
}

void	r_rotate_s(char c, t_ilst *a, t_ilst *b)
{
	r_rotate(0, a);
	r_rotate(0, b);
	if (c)
		write(1, "rrr\n", 4);
}
