/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:49:26 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/22 17:28:58 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include "stdio.h"

void	swap(char c, t_ilst *lst)
{
	int64_t	val;
<<<<<<< HEAD
=======
	int64_t	chunk;
>>>>>>> working push_swap and checker | duplicates checking added
	char	str[3];

	if (lst->next == NULL)
		return ;
	val = lst->next->val;
	chunk = lst->next->chunk;
	lst->next->val = lst->val;
	lst->next->chunk = lst->chunk;
	lst->val = val;
<<<<<<< HEAD
=======
	lst->chunk = chunk;
>>>>>>> working push_swap and checker | duplicates checking added
	if (c)
	{
		str[0] = 's';
		str[1] = c;
		str[2] = '\n';
		write(1, str, 3);
	}
}

<<<<<<< HEAD
void	swap_s(char c, t_ilst *a, t_ilst *b)
{
	swap(0, a);
	swap(0, b);
	if (c)
		write(1, "ss\n", 3);
=======
void	swap_s(char c1, char c2, t_ilst *a, t_ilst *b)
{
	swap(c1, a);
	swap(c2, b);
>>>>>>> working push_swap and checker | duplicates checking added
}
