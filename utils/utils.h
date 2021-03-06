/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:37:11 by sabrugie          #+#    #+#             */
/*   Updated: 2021/03/27 18:58:16 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include "libps.h"

int		is_digit_str(char *str);
int		print_ret(char *str, int ret);
int		stack_operations(t_stack *a, t_stack *b, char *str);
int		check_ilsts(t_ilst *a, t_ilst *b);
void	print_ilst(t_ilst *lst);

#endif
