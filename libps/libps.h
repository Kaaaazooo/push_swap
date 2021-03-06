/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:48:53 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/27 18:48:59 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# define A_ORDER 1
# define D_ORDER 2

typedef struct	s_int_list
{
	int64_t				val;
	int64_t				chunk;
	struct s_int_list	*next;
}				t_ilst;

typedef struct	s_stack
{
	t_ilst		*top;
	t_ilst		*end;
	int32_t		size;
}				t_stack;

void			r_rotate(char c, t_stack *s);
void			r_rotate_s(char c, t_stack *a, t_stack *b);
void			rotate(char c, t_stack *s);
void			rotate_s(char c, t_stack *a, t_stack *b);
void			swap(char c, t_ilst *lst);
void			swap_s(char c, t_ilst *a, t_ilst *b);

void			push(char c, t_stack **dst, t_stack **src);
void			stack_add_front(t_stack *dst, int64_t val);
int				ilst_free_all(t_ilst *lst);
int				ilst_count_sorted(uint8_t flag, t_ilst *lst);
int				ilst_is_sorted(uint8_t flag, t_ilst *lst);
int64_t			get_max(t_ilst *lst);
int64_t			get_min(t_ilst *lst);

void			sort_array(int64_t *tab, int32_t size);
int				check_duplicates(t_ilst *lst, int size);

#endif
