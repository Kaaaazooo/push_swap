/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:33:02 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/22 18:55:28 by sabrugie         ###   ########.fr       */
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
<<<<<<< HEAD
				write(1, " |", 1);
=======
				ft_printf(" |");
>>>>>>> working push_swap and checker | duplicates checking added
			write(1, " ", 1);
		}
		tmp = tmp->next;
//		usleep(100000);
	}
}
