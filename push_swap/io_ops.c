/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:10:00 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 15:39:12 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	print_stack(char *name, t_node *stack)
{
	printf("%s:\n", name);
	while (stack)
	{
		printf("Value: %d | Curr: %d | Target: %d\n", stack->value,
			stack->curr_idx, stack->target_idx);
		stack = stack->next;
	}
	printf("\n");
}

static void	print_strategy(t_info *bench)
{
	if (bench->strategy == LOW_DISORDER)
		printf("[bench] strategy:   Simple / O(n^2)\n");
	else if (bench->strategy == MEDIUM_DISORDER)
		printf("[bench] strategy:   Medium / O(n sqrt n)\n");
	else if (bench->strategy == HIGH_DISORDER)
		printf("[bench] strategy:   Complex / O(n log n)\n");
	else if (bench->notation == NULL)
		printf("[bench] strategy:   Adaptive / O(1)\n");
	else
		printf("[bench] strategy:   Adaptive / %s\n", bench->notation);
}

void	print_bench(t_info *bench)
{
	int	total;

	total = bench->sa + bench->sb + bench->ss + bench->pa + bench->pb
		+ bench->ra + bench->rb + bench->rr + bench->rra + bench->rrb
		+ bench->rrr;
	printf("[bench] disorder:   %d%%\n", (int)(bench->disorder * 100));
	print_strategy(bench);
	printf("[bench] total_ops:  %d\n", total);
	printf("[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n", bench->sa,
		bench->sb, bench->ss, bench->pa, bench->pb);
	printf("[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		bench->ra, bench->rb, bench->rr, bench->rra,
		bench->rrb, bench->rrr);
}
