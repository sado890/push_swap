/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:10:00 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 15:41:31 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_node **a, t_node **b, t_info *bench)
{
	rra(a, 0, bench);
	rrb(b, 0, bench);
	if (bench)
		bench->rrr++;
	if (!(bench && bench->bench_mode))
		write(1, "rrr\n", 4);
}

void	ss(t_node **a, t_node **b, t_info *bench)
{
	sa(a, 0, bench);
	sb(b, 0, bench);
	if (bench)
		bench->ss++;
	if (!(bench && bench->bench_mode))
		write(1, "ss\n", 3);
}

void	rr(t_node **a, t_node **b, t_info *bench)
{
	ra(a, 0, bench);
	rb(b, 0, bench);
	if (bench)
		bench->rr++;
	if (!(bench && bench->bench_mode))
		write(1, "rr\n", 3);
}
