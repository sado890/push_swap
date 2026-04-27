/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 03:45:14 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 04:00:16 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	get_cost(int size, int idx)
{
	if (idx <= size / 2)
		return (idx);
	return (idx - size);
}

static int	get_target_pos(t_node *a, int b_val)
{
	t_node	*tmp = a;
	int		best_idx = -1;
	int		best_val = 2147483647;

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

	tmp = a;
	best_val = 2147483647;
	while (tmp)
	{
		if (tmp->value < best_val)
		{
			best_val = tmp->value;
			best_idx = tmp->curr_idx;
		}
		tmp = tmp->next;
	}
	return (best_idx);
}

static void	do_rotate(t_node **a, t_node **b, int ca, int cb)
{
	while (ca > 0 && cb > 0)
	{
		rr(a, b);
		ca--; cb--;
	}
	while (ca < 0 && cb < 0)
	{
		rrr(a, b);
		ca++; cb++;
	}
	while (ca > 0)
	{
		ra(a, 1);
		ca--;
	}
	while (ca < 0)
	{
		rra(a, 1);
		ca++;
	}
	while (cb > 0)
	{
		rb(b, 1);
		cb--;
	}
	while (cb < 0)
	{
		rrb(b, 1);
		cb++;
	}
}

static void	push_back_cheapest(t_node **a, t_node **b)
{
	t_node	*tmp;
	int		best = 2147483647;
	int		best_a = 0;
	int		best_b = 0;

	set_current_and_target_idx(*a);
	set_current_indices(*b);

	tmp = *b;
	while (tmp)
	{
		int target = get_target_pos(*a, tmp->value);
		int ca = get_cost(stack_len(*a), target);
		int cb = get_cost(stack_len(*b), tmp->curr_idx);
		int total = abs(ca) + abs(cb);

		if (total < best)
		{
			best = total;
			best_a = ca;
			best_b = cb;
		}
		tmp = tmp->next;
	}

	do_rotate(a, b, best_a, best_b);
	pa(a, b, 1);
}

static void	push_chunks(t_node **a, t_node **b)
{
	int	chunk = 30;
	int	pushed = 0;

	while (*a)
	{
		set_current_and_target_idx(*a);

		if ((*a)->target_idx <= pushed)
		{
			pb(b, a, 1);
			rb(b, 1);
			pushed++;
		}
		else if ((*a)->target_idx <= pushed + chunk)
		{
			pb(b, a, 1);
			pushed++;
		}
		else
			ra(a, 1);
	}
}

static void	final_align(t_node **a)
{
	int		min_idx = 0;
	t_node	*tmp;

	set_current_and_target_idx(*a);
	tmp = *a;

	while (tmp)
	{
		if (tmp->target_idx == 0)
			break;
		min_idx++;
		tmp = tmp->next;
	}

	if (min_idx <= (int)stack_len(*a) / 2)
	{
		while (min_idx--)
			ra(a, 1);
	}
	else
	{
		while (min_idx++ < (int)stack_len(*a))
			rra(a, 1);
	}
}

void	medium_sort(t_node *a, t_node *b)
{
	t_node *pa = a;
	t_node *pb = b;

	push_chunks(&pa, &pb);

	while (pb)
		push_back_cheapest(&pa, &pb);

	final_align(&pa);
}
