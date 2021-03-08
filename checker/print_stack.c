/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:33:02 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/08 12:36:05 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_ilst(t_ilst *lst)
{
	t_ilst	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_printf("%ld\n", tmp->val);
		tmp = tmp->next;
	}
}
