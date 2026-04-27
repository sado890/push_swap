/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 00:12:45 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 19:52:29 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_small_size(t_node *a, t_node *b, int size, t_info *bench)
{
	if (size == 5)
		sort_5(a, b, bench);
	else if (size == 4)
		sort_4(a, b, bench);
	else if (size == 3)
		sort_3(a, bench);
	else if (size == 2)
		sort_2(a, bench);
	else
		return (-1);
	return (0);
}

static void	radix_sort(t_node **a, t_node **b, int size, t_info *bench)
{
	int	max_bits;
	int	i;
	int	j;

	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->target_idx >> i) & 1) == 0)
				pb(b, a, 1, bench);
			else
				ra(a, 1, bench);
			j++;
		}
		while (*b)
			pa(a, b, 1, bench);
		i++;
	}
}

void	complex_sort(t_node *a, t_node *b, t_info *bench)
{
	int	size;

	set_current_and_target_idx(a);
	size = (int)stack_len(a);
	if (handle_small_size(a, b, size, bench) != -1)
		return ;
	if (size <= 100)
	{
		medium_sort(a, b, bench);
		return ;
	}
	radix_sort(&a, &b, size, bench);
}
