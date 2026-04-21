/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:10:00 by muarici           #+#    #+#             */
/*   Updated: 2026/04/16 18:04:39 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(char *name, t_node *stack)
{
	printf("%s: ", name);
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}
