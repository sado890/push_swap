/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 01:23:43 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 15:33:57 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_strategy(t_node *a, t_node *b, t_strategy strat, t_info *bench)
{
	if (strat == LOW_DISORDER)
	{
		bench->notation = "O(n^2)";
		simple_sort(a, b, bench);
	}
	else if (strat == MEDIUM_DISORDER)
	{
		bench->notation = "O(n√n)";
		medium_sort(a, b, bench);
	}
	else if (strat == HIGH_DISORDER)
	{
		bench->notation = "O(n log n)";
		complex_sort(a, b, bench);
	}
	else if (strat == ADAPTIVE)
	{
		execute_adaptive_sort(a, b, bench);
	}
	else
		write(1, "error\n", 7);
}

void	execute_adaptive_sort(t_node *a, t_node *b, t_info *bench)
{
	float		disorder;
	t_strategy	strat;

	set_current_and_target_idx(a);
	disorder = compute_disorder(a);
	if (disorder < 0.2f)
		strat = LOW_DISORDER;
	else if (disorder >= 0.2f && disorder <= 0.5f)
		strat = MEDIUM_DISORDER;
	else
		strat = HIGH_DISORDER;
	run_strategy(a, b, strat, bench);
}
