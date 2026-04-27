/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 00:12:45 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 19:52:29 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_small_size(t_node **a, t_node **b, int size, t_info *bench)
{
	if (size == 5)
		sort_5(a, b, bench);
	else if (size == 4)
		sort_4(a, b, bench);
	else if (size == 3)
		sort_3(a, bench);
	else if (size == 2)
		sort_2(a, bench);
	else
		return (-1);
	return (0);
}

static void	init_lis_arrays(t_node *a, int *arr, int *lis, int *parent)
{
	int	i;

	i = 0;
	while (a)
	{
		arr[i] = a->target_idx;
		lis[i] = 1;
		parent[i] = -1;
		a->curr_idx = 0;
		a = a->next;
		i++;
	}
}

static int	calc_lis(int *arr, int *lis, int *parent, int size)
{
	int	i;
	int	j;
	int	max;
	int	best;

	max = 1;
	best = 0;
	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				parent[i] = j;
			}
			j++;
		}
		if (lis[i] > max)
		{
			max = lis[i];
			best = i;
		}
		i++;
	}
	return (best);
}

static void	mark_lis(t_node *a, int size)
{
	int		*arr;
	int		*lis;
	int		*parent;
	t_node	*tmp;
	int		curr;
	int		j;

	arr = malloc(sizeof(int) * size);
	lis = malloc(sizeof(int) * size);
	parent = malloc(sizeof(int) * size);
	if (!arr || !lis || !parent)
	{
		free(arr);
		free(lis);
		free(parent);
		return ;
	}
	init_lis_arrays(a, arr, lis, parent);
	curr = calc_lis(arr, lis, parent, size);
	while (curr != -1)
	{
		tmp = a;
		j = 0;
		while (j++ < curr)
			tmp = tmp->next;
		tmp->curr_idx = 1;
		curr = parent[curr];
	}
	free(arr);
	free(lis);
	free(parent);
}

static void	push_non_lis(t_node **a, t_node **b, t_info *bench, int size)
{
	int	i;

	mark_lis(*a, size);
	i = 0;
	while (i < size)
	{
		if ((*a)->curr_idx == 0)
		{
			pb(b, a, 1, bench);
			if (stack_len(*b) > 1 && (*b)->target_idx < size / 2)
				rb(b, 1, bench);
		}
		else
			ra(a, 1, bench);
		i++;
	}
}

void	complex_sort(t_node **a, t_node **b, t_info *bench)
{
	int	size;

	set_current_and_target_idx(*a);
	size = (int)stack_len(*a);
	if (handle_small_size(a, b, size, bench) != -1)
		return ;
	push_non_lis(a, b, bench, size);
	while (*b)
		push_back_cheapest(a, b, bench);
	final_align(a, bench);
}
