/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 03:45:14 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 17:18:38 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_back_cheapest(t_node **a, t_node **b, t_info *bench)
{
	t_node	*tmp;
	int		best_val;
	int		move[2];
	int		curr[2];

	best_val = 2147483647;
	set_current_and_target_idx(*a);
	set_current_indices(*b);
	tmp = *b;
	while (tmp)
	{
		curr[0] = get_cost(stack_len(*a), get_target_pos(*a, tmp->value));
		curr[1] = get_cost(stack_len(*b), tmp->curr_idx);
		if (abs(curr[0]) + abs(curr[1]) < best_val)
		{
			best_val = abs(curr[0]) + abs(curr[1]);
			move[0] = curr[0];
			move[1] = curr[1];
		}
		tmp = tmp->next;
	}
	do_rotate(a, b, move[0], move[1], bench);
	pa(a, b, 1, bench);
}

static void	push_chunks(t_node **a, t_node **b, t_info *bench)
{
	int	chunk;
	int	pushed;

	chunk = 30;
	pushed = 0;
	while (*a)
	{
		set_current_and_target_idx(*a);
		if ((*a)->target_idx <= pushed)
		{
			pb(b, a, 1, bench);
			rb(b, 1, bench);
			pushed++;
		}
		else if ((*a)->target_idx <= pushed + chunk)
		{
			pb(b, a, 1, bench);
			pushed++;
		}
		else
			ra(a, 1, bench);
	}
}

static void	final_align(t_node **a, t_info *bench)
{
	int		min_idx;
	t_node	*tmp;

	min_idx = 0;
	set_current_and_target_idx(*a);
	tmp = *a;
	while (tmp && tmp->target_idx != 0)
	{
		min_idx++;
		tmp = tmp->next;
	}
	if (min_idx <= (int)stack_len(*a) / 2)
	{
		while (min_idx--)
			ra(a, 1, bench);
	}
	else
	{
		while (min_idx++ < (int)stack_len(*a))
			rra(a, 1, bench);
	}
}

void	medium_sort(t_node *a, t_node *b, t_info *bench)
{
	int	len;

	len = (int)stack_len(a);
	if (handle_small_size(a, b, len, bench) != -1)
		return ;
	push_chunks(&a, &b, bench);
	while (b)
		push_back_cheapest(&a, &b, bench);
	final_align(&a, bench);
}
