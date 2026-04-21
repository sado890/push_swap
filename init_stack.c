/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:10:00 by muarici           #+#    #+#             */
/*   Updated: 2026/04/16 18:04:39 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_to_nodes(t_node **a, char **split)
{
	int	i;
	int	val;
	int	err;

	i = 0;
	while (split[i])
	{
		err = 0;
		val = ft_atoi_check(split[i], &err);
		if (err || is_duplicate(*a, val))
			return (-1);
		add_back(a, new_node(val));
		i++;
	}
	return (0);
}
