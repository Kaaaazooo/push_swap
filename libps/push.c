/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:49:04 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/22 17:25:15 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	push(char c, t_stack **dst, t_stack **src)
{
	t_ilst	*tmp;
	char	str[3];

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
	if (c)
	{
		str[0] = 'p';
		str[1] = c;
		str[2] = '\n';
		write(1, str, 3);
	}
}
