/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 04:22:31 by muarici           #+#    #+#             */
/*   Updated: 2026/04/24 16:50:36 by muarici          ###   ########.fr       */
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
t_node	*insertion_sort(t_node *a, t_node *b)
{
	t_node	*temp;
	int		b_len;
	while (a)
	{
		if (b == NULL || a->value > b->value)
			pb(&b, &a, 1);
		else if (b != NULL && a->value < b->value)
		{
			temp = b;
			while (temp->next != NULL)
				temp = temp->next;
			if (a->value < temp->value)
			{
				pb(&b, &a, 1);
				rb(&b, 1);
			}
			else
			{
				b_len = stack_len(b);
				while (b_len > 0 && a->value < b->value)
				{
					rb(&b, 1);
					b_len--;
				}
				pb(&b, &a, 1);
                while (b_len >= 0)
                {
                    rb(&b, 1);
                    b_len--;
                }
			}
		}
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
	return (insertion_sort(a, b));
}