/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:38:55 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/27 18:39:04 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int64_t	get_median(t_ilst *lst, int32_t size)
{
	int64_t	*values;
	int64_t	median;
	int		i;

	if (!lst || size == 0)
		exit(0);
	values = malloc(sizeof(int64_t) * size);
	if (!values)
	{
		ft_printf("malloc failed\n");
		exit(0);
	}
	i = 0;
	while (i < size)
	{
		values[i] = lst->val;
		lst = lst->next;
		++i;
	}
	sort_array(values, size);
	median = values[size / 2];
	free(values);
	return (median);
}
