/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 00:12:45 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 04:18:00 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_inputs(t_node *a, t_node *b, int size)
{
	if (size == 5)
		sort_5(a, b);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 3)
		sort_3(a);
	else if (size == 2)
		sort_2(a);
	else
		return (-1);
	return (0);
}

void	complex_sort(t_node *a, t_node *b)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;
	int		max_bits;
	int		i;
	int		j;

	stack_a = a;
	stack_b = b;

	set_current_and_target_idx(stack_a);
	size = (int)stack_len(stack_a);
	i = check_inputs(a, b, size);
	if (i != -1)
		return ;
	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((stack_a->target_idx >> i) & 1) == 0)
				pb(&stack_b, &stack_a, 1);
			else
				ra(&stack_a, 1);
			j++;
		}
		while (stack_b)
			pa(&stack_a, &stack_b, 1);
		i++;
	}
}