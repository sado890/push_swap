
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

static void	rotate_both(t_node **a, t_node **b, int *ca, int *cb, t_info *bench)
{
	while (*ca > 0 && *cb > 0)
	{
		rr(a, b, bench);
		(*ca)--;
		(*cb)--;
	}
	while (*ca < 0 && *cb < 0)
	{
		rrr(a, b, bench);
		(*ca)++;
		(*cb)++;
	}
}

void	do_rotate(t_node **a, t_node **b, int *moves, t_info *bench)
{
	int	ca;
	int	cb;

	ca = moves[0];
	cb = moves[1];
	rotate_both(a, b, &ca, &cb, bench);
	while (ca > 0 && ca--)
		ra(a, 1, bench);
	while (ca < 0 && ca++)
		rra(a, 1, bench);
	while (cb > 0 && cb--)
		rb(b, 1, bench);
	while (cb < 0 && cb++)
		rrb(b, 1, bench);
}