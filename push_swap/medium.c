/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 03:45:14 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 20:06:25 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_align(t_node **a, t_info *bench)
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

void	medium_sort(t_node **a, t_node **b, t_info *bench)
{
	int	len;

	len = (int)stack_len(*a);
	if (handle_small_size(a, b, len, bench) != -1)
		return ;
	push_chunks(a, b, bench);
	while (*b)
		push_back_cheapest(a, b, bench);
	final_align(a, bench);
}
