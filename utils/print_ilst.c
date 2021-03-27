/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:33:02 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/27 18:58:27 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_ilst(t_ilst *lst)
{
	t_ilst	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_printf("%ld [%ld] ", tmp->val, tmp->chunk);
		if (tmp->next)
		{
			if (tmp->next->chunk != tmp->chunk)
				write(1, " |", 1);
			write(1, " ", 1);
		}
		tmp = tmp->next;
	}
}
