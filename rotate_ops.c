/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:00:00 by muarici           #+#    #+#             */
/*   Updated: 2026/04/16 18:04:39 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a, int print)
{
	t_node	*first;
	t_node	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_node **b, int print)
{
	t_node	*first;
	t_node	*last;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	first->next = NULL;
	last->next = first;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}

void	rra(t_node **a, int print)
{
	t_node	*last;
	t_node	*prev;

	if (!*a || !(*a)->next)
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, int print)
{
	t_node	*last;
	t_node	*prev;

	if (!*b || !(*b)->next)
		return ;
	prev = NULL;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	if (print)
		write(1, "rrb\n", 4);
}
