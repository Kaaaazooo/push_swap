/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:49:09 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/22 19:16:47 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

<<<<<<< HEAD
void	rotate(char c, t_ilst **lst)
{
	t_ilst	*tmp;
	t_ilst	*tmp1;
	int64_t	val;
	char	str[3];

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	tmp = *lst;
	while ((*lst)->next)
	{
		tmp1 = *lst;
		*lst = (*lst)->next;
	}
	(*lst)->next = tmp;
	(*lst) = tmp1;
	(*lst)->next = NULL;
	if (c)
	{
=======
//void	rotate(char c, t_ilst *lst)
//{
//	t_ilst	*tmp;
//	int64_t	val;
//	int64_t	chunk;
//	char	str[3];
//
//	if (lst == NULL || lst->next == NULL)
//		return ;
//	tmp = lst;
//	val = lst->val;
//	chunk = lst->chunk;
//	while (tmp->next)
//	{
//		tmp->val = tmp->next->val;
//		tmp->chunk = tmp->next->chunk;
//		tmp = tmp->next;
//	}
//	tmp->val = val;
//	tmp->chunk = chunk;
//	if (c)
//	{
//		str[0] = 'r';
//		str[1] = c;
//		str[2] = '\n';
//		write(1, str, 3);
//	}
//}

#include <stdio.h>

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
>>>>>>> working push_swap and checker | duplicates checking added
		str[0] = 'r';
		str[1] = c;
		str[2] = '\n';
		write(1, str, 3);
	}
}

<<<<<<< HEAD
void	rotate_s(char c, t_ilst *a, t_ilst *b)
{
	rotate(0, a);
	rotate(0, b);
	if (c)
		write(1, "rr\n", 3);
}

void	r_rotate(char c, t_ilst *lst)
{
	t_ilst	*tmp;
	int64_t	val;
	int64_t	tmp_val;
=======
void	rotate_s(char c1, char c2, t_stack *a, t_stack *b)
{
	rotate(c1, a);
	rotate(c2, b);
}

void	r_rotate(char c, t_stack *s)
{
	t_ilst	*tmp;
	t_ilst	*first;
>>>>>>> working push_swap and checker | duplicates checking added
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
<<<<<<< HEAD
	lst->val = tmp_val;
	if (c)
	{
		str[0] = 'r';
		str[1] = 'r';
		str[2] = c;
		str[3] = '\n';
		write(1, str, 4);
	}
}

void	r_rotate_s(char c, t_ilst *a, t_ilst *b)
{
	r_rotate(0, a);
	r_rotate(0, b);
	if (c)
		write(1, "rrr\n", 4);
=======
}

void	r_rotate_s(char c1, char c2, t_stack *a, t_stack *b)
{
	r_rotate(c1, a);
	r_rotate(c2, b);
>>>>>>> working push_swap and checker | duplicates checking added
}
