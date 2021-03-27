/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:55:24 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/27 18:55:25 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdint.h>
# include "libft.h"
# include "libps.h"
# include "utils.h"

typedef struct	s_chunk_parameters
{
	int64_t		median;
	int64_t		id;
	int			size;
}				t_chk_params;

int64_t			chunk_max(t_ilst *lst, int64_t chunk);
int64_t			chunk_min(t_ilst *lst, int64_t chunk);
int				chunk_size(t_ilst *lst, int64_t chunk);
int64_t			biggest_chunk(t_ilst *a, t_ilst *b);

int64_t			get_median(t_ilst *lst, int32_t size);

void			mid_sort_a(int64_t *chunk, t_stack **a, t_stack **b);
void			mid_sort_b(int64_t *chunk, t_stack **a, t_stack **b);
void			fill_a(t_stack **a, t_stack **b);

#endif
