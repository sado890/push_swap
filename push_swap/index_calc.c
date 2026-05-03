/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 04:41:59 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 15:38:59 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_and_target_idx(t_node *stack)
{
	set_current_indices(stack);
	set_target_indices(stack);
}

void	set_current_indices(t_node *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		stack->curr_idx = index++;
		stack = stack->next;
	}
}

void	set_target_indices(t_node *stack)
{
	t_node	*temp;
	t_node	*current;
	int		count;

	current = stack;
	while (current)
	{
		count = 0;
		temp = stack;
		while (temp)
		{
			if (temp->value < current->value)
				count++;
			temp = temp->next;
		}
		current->target_idx = count;
		current = current->next;
	}
}
