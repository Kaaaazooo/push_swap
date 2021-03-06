/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:57:30 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/27 18:57:32 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	sort_array(int64_t *tab, int32_t size)
{
	int64_t	c;
	int64_t	d;
	int64_t	t;

	c = 0;
	while (c < (int64_t)(size - 1))
	{
		d = 0;
		while (d < ((int64_t)size - 1) - c)
		{
			if (tab[d] > tab[d + 1])
			{
				t = tab[d];
				tab[d] = tab[d + 1];
				tab[d + 1] = t;
			}
			++d;
		}
		++c;
	}
}
