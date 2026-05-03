/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:17:44 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 17:24:55 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cost(int size, int idx)
{
	if (idx <= size / 2)
		return (idx);
	return (idx - size);
}

static int	find_min_pos(t_node *a)
{
	int		min_val;
	int		min_idx;
	t_node	*tmp;

	min_val = 2147483647;
	min_idx = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_idx = tmp->curr_idx;
		}
		tmp = tmp->next;
	}
	return (min_idx);
}

int	get_target_pos(t_node *a, int b_val)
{
	t_node	*tmp;
	int		best_idx;
	int		best_val;

	tmp = a;
	best_idx = -1;
	best_val = 2147483647;
	while (tmp)
	{
		if (tmp->value > b_val && tmp->value < best_val)
		{
			best_val = tmp->value;
			best_idx = tmp->curr_idx;
		}
		tmp = tmp->next;
	}
	if (best_idx != -1)
		return (best_idx);
	return (find_min_pos(a));
}

static void	rotate_both(t_node **a, t_node **b, int *cost, t_info *bench)
{
	while (cost[0] > 0 && cost[1] > 0)
	{
		rr(a, b, bench);
		cost[0]--;
		cost[1]--;
	}
	while (cost[0] < 0 && cost[1] < 0)
	{
		rrr(a, b, bench);
		cost[0]++;
		cost[1]++;
	}
}

void	do_rotate(t_node **a, t_node **b, int *moves, t_info *bench)
{
	int	cost[2];

	cost[0] = moves[0];
	cost[1] = moves[1];
	rotate_both(a, b, cost, bench);
	while (cost[0] > 0 && cost[0]--)
		ra(a, 1, bench);
	while (cost[0] < 0 && cost[0]++)
		rra(a, 1, bench);
	while (cost[1] > 0 && cost[1]--)
		rb(b, 1, bench);
	while (cost[1] < 0 && cost[1]++)
		rrb(b, 1, bench);
}
