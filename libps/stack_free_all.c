/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:49:22 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/08 12:51:58 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ilst_free_all(t_ilst *lst)
{
	t_ilst	*next;

	while (lst)
	{
		next = lst->next;
		lst->val = 0;
		lst->next = NULL;
		free(lst);
		lst = next;
	}
	return (0);
}
