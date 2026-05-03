/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_lis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 00:00:00 by muarici           #+#    #+#             */
/*   Updated: 2026/04/28 00:00:00 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	update_lis_at(int i, int *arr, int *lis, int *parent)
{
	int	j;

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
}

static int	calc_lis(int *arr, int *lis, int *parent, int size)
{
	int	i;
	int	max;
	int	best;

	max = 1;
	best = 0;
	i = 1;
	while (i < size)
	{
		update_lis_at(i, arr, lis, parent);
		if (lis[i] > max)
		{
			max = lis[i];
			best = i;
		}
		i++;
	}
	return (best);
}

static void	mark_lis_nodes(t_node *a, int *parent, int curr)
{
	t_node	*tmp;
	int		j;

	while (curr != -1)
	{
		tmp = a;
		j = 0;
		while (j < curr)
		{
			tmp = tmp->next;
			j++;
		}
		tmp->curr_idx = 1;
		curr = parent[curr];
	}
}

void	mark_lis(t_node *a, int size)
{
	int	*arr;
	int	*lis;
	int	*parent;
	int	curr;

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
	mark_lis_nodes(a, parent, curr);
	free(arr);
	free(lis);
	free(parent);
}
