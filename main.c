/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:46:40 by muarici           #+#    #+#             */
/*   Updated: 2026/04/24 03:34:58 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --- Main --- */

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**split;
	int		i;

	i = 1;
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		split = ft_split(argv[i]);
		if (!split || !split[0] || fill_stack(&a, split) == -1)
		{
			if (split)
				free_split(split);
			free_stack(&a);
			write(2, "Error\n", 6);
			return (1);
		}
		free_split(split);
		i++;
	}
	set_current_and_target_idx(a);
	a = simple_sort(a, b);
	free_stack(&a);
	return (0);
}