/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:21:01 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 15:41:43 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_idx(t_node *a)
{
	t_node	*temp;

	temp = a;
	while (temp)
	{
		if (temp->target_idx == 0)
			return (temp->curr_idx);
		temp = temp->next;
	}
	return (0);
}

static void	rotate_to_top(t_node **a, int min_idx, int size, t_info *bench)
{
	if (min_idx <= size / 2)
	{
		while (min_idx-- > 0)
			ra(a, 1, bench);
	}
	else
	{
		while (min_idx++ < size)
			rra(a, 1, bench);
	}
}

void	simple_sort(t_node **a, t_node **b, t_info *bench)
{
	int		size;
	int		min_idx;

	size = (int)stack_len(*a);
	while ((int)stack_len(*a) > 3)
	{
		set_current_and_target_idx(*a);
		size = (int)stack_len(*a);
		min_idx = get_min_idx(*a);
		rotate_to_top(a, min_idx, size, bench);
		pb(b, a, 1, bench);
	}
	sort_3(a, bench);
	while (*b)
		pa(a, b, 1, bench);
}
