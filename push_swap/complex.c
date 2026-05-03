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

static void	push_non_lis(t_node **a, t_node **b, t_info *bench, int size)
{
	int	i;

	mark_lis(*a, size);
	i = 0;
	while (i < size)
	{
		if ((*a)->curr_idx == 0)
		{
			pb(b, a, 1, bench);
			if (stack_len(*b) > 1 && (*b)->target_idx < size / 2)
				rb(b, 1, bench);
		}
		else
			ra(a, 1, bench);
		i++;
	}
}

void	complex_sort(t_node **a, t_node **b, t_info *bench)
{
	int	size;

	set_current_and_target_idx(*a);
	size = (int)stack_len(*a);
	if (handle_small_size(a, b, size, bench) != -1)
		return ;
	push_non_lis(a, b, bench, size);
	while (*b)
		push_back_cheapest(a, b, bench);
	final_align(a, bench);
}
