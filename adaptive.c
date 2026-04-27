/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 01:23:43 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 04:07:03 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void run_strategy(t_node *a, t_node *b, t_strategy strat)
{
    if (strat == LOW_DISORDER)
        simple_sort(a, b);
    else if (strat == MEDIUM_DISORDER)
        medium_sort(a, b);
    else
		complex_sort(a, b);
}
void execute_adaptive_sort(t_node *a, t_node *b)
{
	float disorder;
    t_strategy strat;
	
	set_current_and_target_idx(a);
	disorder = compute_disorder(a);

    if (disorder < 0.2f)
        strat = LOW_DISORDER;
    else if (disorder >= 0.2f || disorder <= 0.5f)
        strat = MEDIUM_DISORDER;
    else
        strat = HIGH_DISORDER;

    run_strategy(a, b, strat);
}