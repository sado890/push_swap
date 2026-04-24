/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 03:03:40 by muarici           #+#    #+#             */
/*   Updated: 2026/04/24 03:38:17 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*simple yapmadan önce yazmıştım ama gerek yokmuş şimdilik kalsın*/

t_node	*sort_2(t_node *a)
{
	if (a->target_idx > a->next->target_idx)
		sa(&a, 1);
	return (a);
}

t_node	*sort_3(t_node *a)
{
    set_current_and_target_idx(a);
	if (a->target_idx == 0 && a->next->target_idx == 2)
    {
        sa(&a, 1);
        ra(&a, 1);
    }
    else if (a->target_idx == 1 && a->next->target_idx == 0)
		sa(&a, 1);
	else if (a->target_idx == 1 && a->next->target_idx == 2)
		rra(&a, 1);
	else if (a->target_idx == 2 && a->next->target_idx == 0)
		ra(&a, 1);
	else if (a->target_idx == 2 && a->next->target_idx == 1)
	{
		sa(&a, 1);
		rra(&a, 1);
	}
    set_current_and_target_idx(a);
	return (a);
}

t_node	*sort_4(t_node *a, t_node *b)
{
    while (a->target_idx != 0)
        ra(&a, 1);
    pb(&b, &a, 1);
    a = sort_3(a);
    pa(&a, &b, 1);
    set_current_and_target_idx(a);
	return (a);
}

t_node	*sort_5(t_node *a, t_node *b)
{
    while (a->target_idx != 0)
        ra(&a, 1);
    pb(&b, &a, 1);
    set_current_and_target_idx(a);
    sort_4(a, b);
    pa(&a, &b, 1);
    set_current_and_target_idx(a);
    return (a);
}