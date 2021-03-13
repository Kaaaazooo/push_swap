/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:49:04 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/08 12:49:05 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	push(t_stack **dst, t_stack **src)
{
	t_ilst	*tmp;

	if ((*src)->top == NULL)
		return ;
	tmp = (*dst)->top;
	(*dst)->top = (*src)->top;
	(*src)->top = (*src)->top->next;
	--(*src)->size;
	++(*dst)->size;
	if ((*src)->top == NULL)
		(*src)->end = NULL;
	if (tmp == NULL)
		(*dst)->end = (*dst)->top;
	(*dst)->top->next = tmp;
}
