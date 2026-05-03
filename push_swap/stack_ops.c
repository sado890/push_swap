/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:00:00 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 15:41:03 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a, int print, t_info *bench)
{
	t_node	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
	if (bench)
		bench->sa++;
	if (print && !(bench && bench->bench_mode))
		write(1, "sa\n", 3);
}

void	sb(t_node **b, int print, t_info *bench)
{
	t_node	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
	if (bench)
		bench->sb++;
	if (print && !(bench && bench->bench_mode))
		write(1, "sb\n", 3);
}

void	pa(t_node **a, t_node **b, int print, t_info *bench)
{
	t_node	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	if (bench)
		bench->pa++;
	if (print && !(bench && bench->bench_mode))
		write(1, "pa\n", 3);
}

void	pb(t_node **b, t_node **a, int print, t_info *bench)
{
	t_node	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (bench)
		bench->pb++;
	if (print && !(bench && bench->bench_mode))
		write(1, "pb\n", 3);
}
