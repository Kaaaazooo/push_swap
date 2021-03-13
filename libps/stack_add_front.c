/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:49:17 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/08 12:49:18 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	stack_add_front(t_stack *dst, int64_t val)
{
	t_ilst	*new;

	new = (t_ilst *)malloc(sizeof(t_ilst));
	if (new == NULL)
		return ;
	++dst->size;
	if (dst->top == NULL)
	{
		dst->size = 1;
		dst->end = new;
	}
	new->val = val;
	new->next = dst->top;
	dst->top = new;
}
