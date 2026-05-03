/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 00:00:00 by muarici           #+#    #+#             */
/*   Updated: 2026/04/28 00:00:00 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_best_move(t_node **a, t_node **b, t_node *tmp, int *move)
{
	int	curr[2];
	int	cost;

	curr[0] = get_cost(stack_len(*a), get_target_pos(*a, tmp->value));
	curr[1] = get_cost(stack_len(*b), tmp->curr_idx);
	cost = abs(curr[0]) + abs(curr[1]);
	if (cost < move[2])
	{
		move[2] = cost;
		move[0] = curr[0];
		move[1] = curr[1];
	}
}

void	push_back_cheapest(t_node **a, t_node **b, t_info *bench)
{
	t_node	*tmp;
	int		move[3];

	move[2] = 2147483647;
	set_current_and_target_idx(*a);
	set_current_indices(*b);
	tmp = *b;
	while (tmp)
	{
		update_best_move(a, b, tmp, move);
		tmp = tmp->next;
	}
	do_rotate(a, b, move, bench);
	pa(a, b, 1, bench);
}

static void	push_chunk_node(t_node **a, t_node **b, int *pushed,
		t_info *bench)
{
	pb(b, a, 1, bench);
	if ((*b)->target_idx < *pushed / 2)
		rb(b, 1, bench);
	(*pushed)++;
}

void	push_chunks(t_node **a, t_node **b, t_info *bench)
{
	int	size;
	int	chunk;
	int	pushed;

	size = (int)stack_len(*a);
	set_current_and_target_idx(*a);
	chunk = size / 11;
	if (size <= 100)
		chunk = size / 6;
	pushed = 0;
	while (*a)
	{
		if ((*a)->target_idx <= pushed)
			push_chunk_node(a, b, &pushed, bench);
		else if ((*a)->target_idx <= pushed + chunk)
		{
			pb(b, a, 1, bench);
			pushed++;
		}
		else
			ra(a, 1, bench);
	}
}
