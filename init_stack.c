/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:10:00 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 19:48:33 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_and_fill_all(t_node **a, int argc, char **argv, int i)
{
	char	**split;
	int		res;

	while (i < argc)
	{
		split = ft_split(argv[i]);
		if (!split)
			return (-1);
		if (!split[0])
		{
			free_split(split);
			return (-1);
		}
		res = fill_stack(a, split);
		free_split(split);
		if (res == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	fill_stack(t_node **a, char **split)
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
