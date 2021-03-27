/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:49:09 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/27 18:51:25 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	rotate(char c, t_stack *s)
{
	t_ilst	*tmp;
	t_ilst	*tmp_next;
	char	str[3];

	if (s->top == NULL || s->top->next == NULL)
		return ;
	tmp = s->top;
	tmp_next = s->top->next;
	s->top->next = NULL;
	s->top = tmp_next;
	while (s->top->next)
		s->top = s->top->next;
	s->top->next = tmp;
	s->end = tmp;
	s->top = tmp_next;
	if (c)
	{
		str[0] = 'r';
		str[1] = c;
		str[2] = '\n';
		write(1, str, 3);
	}
}

void	rotate_s(char c, t_stack *a, t_stack *b)
{
	rotate(0, a);
	rotate(0, b);
	if (c)
		write(1, "rr\n", 3);
}

void	r_rotate(char c, t_stack *s)
{
	t_ilst	*tmp;
	t_ilst	*first;
	char	str[4];

	if (s->top == NULL || s->top->next == NULL)
		return ;
	tmp = s->top;
	first = s->top;
	while (tmp->next)
		tmp = tmp->next;
	while (s->top->next != tmp)
		s->top = s->top->next;
	s->top->next = NULL;
	s->end = s->top;
	s->top = tmp;
	s->top->next = first;
	if (c)
	{
		str[0] = 'r';
		str[1] = 'r';
		str[2] = c;
		str[3] = '\n';
		write(1, str, 4);
	}
}

void	r_rotate_s(char c, t_stack *a, t_stack *b)
{
	r_rotate(0, a);
	r_rotate(0, b);
	if (c)
		write(1, "rrr\n", 4);
}
