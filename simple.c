/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 04:22:31 by muarici           #+#    #+#             */
/*   Updated: 2026/04/24 03:34:43 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*selection_sort(t_node *a, t_node *b)
{
    while (a)
    {
        while (a->target_idx != 0)
            ra(&a, 1);
        pb(&b, &a, 1);
        set_current_and_target_idx(a);
    }
    while (b)
    {
        pa(&a, &b, 1);
    }
    return (a);
}

t_node	*simple_sort(t_node *a, t_node *b)
{
	size_t	list_size;

	list_size = stack_len(a);
    if (list_size >= 1)
        return (selection_sort(a, b));
	else if (list_size == 5)
		return (sort_5(a, b));
	else if (list_size == 4)
		return (sort_4(a, b));
	else if (list_size == 3)
		return (sort_3(a));
	else if (list_size == 2)
		return (sort_2(a));
	return (a);
}