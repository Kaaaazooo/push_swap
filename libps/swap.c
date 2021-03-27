/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:49:26 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/27 19:42:23 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include "stdio.h"

void	swap(char c, t_ilst *lst)
{
	int64_t	val;
	int64_t	chunk;
	char	str[3];

	if (lst == NULL || lst->next == NULL)
		return ;
	val = lst->next->val;
	chunk = lst->next->chunk;
	lst->next->val = lst->val;
	lst->next->chunk = lst->chunk;
	lst->val = val;
	lst->chunk = chunk;
	if (c)
	{
		str[0] = 's';
		str[1] = c;
		str[2] = '\n';
		write(1, str, 3);
	}
}

void	swap_s(char c, t_ilst *a, t_ilst *b)
{
	swap(0, a);
	swap(0, b);
	if (c)
		write(1, "ss\n", 3);
}
