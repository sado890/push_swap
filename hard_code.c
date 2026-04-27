/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 03:03:40 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 19:54:59 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*sort_2(t_node **a, t_info *bench)
{
	if ((*a)->target_idx > (*a)->next->target_idx)
		sa(a, 1, bench);
	return (*a);
}

t_node	*sort_3(t_node **a, t_info *bench)
{
	set_current_and_target_idx(*a);
	if ((*a)->target_idx == 0 && (*a)->next->target_idx == 2)
	{
		sa(a, 1, bench);
		ra(a, 1, bench);
	}
	else if ((*a)->target_idx == 1 && (*a)->next->target_idx == 0)
		sa(a, 1, bench);
	else if ((*a)->target_idx == 1 && (*a)->next->target_idx == 2)
		rra(a, 1, bench);
	else if ((*a)->target_idx == 2 && (*a)->next->target_idx == 0)
		ra(a, 1, bench);
	else if ((*a)->target_idx == 2 && (*a)->next->target_idx == 1)
	{
		sa(a, 1, bench);
		rra(a, 1, bench);
	}
	set_current_and_target_idx(*a);
	return (*a);
}

t_node	*sort_4(t_node **a, t_node **b, t_info *bench)
{
	while ((*a)->target_idx != 0)
		ra(a, 1, bench);
	pb(b, a, 1, bench);
	sort_3(a, bench);
	pa(a, b, 1, bench);
	set_current_and_target_idx(*a);
	return (*a);
}

t_node	*sort_5(t_node **a, t_node **b, t_info *bench)
{
	int	len;

	len = 5;
	while ((*a)->target_idx != 0)
	{
		if (get_target_pos(*a, 0) > len / 2)
			rra(a, 1, bench);
		else
			ra(a, 1, bench);
	}
	pb(b, a, 1, bench);
	set_current_and_target_idx(*a);
	sort_4(a, b, bench);
	pa(a, b, 1, bench);
	set_current_and_target_idx(*a);
	return (*a);
}
