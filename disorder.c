/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 03:14:55 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 16:53:17 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static float	count_inversions(t_node *node)
{
	t_node	*temp;
	float	counter;

	temp = node->next;
	counter = 0;
	while (temp)
	{
		if (node->value > temp->value)
		{
			counter++;
		}
		temp = temp->next;
	}
	return (counter);
}

float	compute_disorder(t_node *a)
{
	float	mistakes;
	size_t	len;
	float	total_pairs;
	t_node	*temp;

	len = 0;
	total_pairs = 0;
	temp = a;
	mistakes = 0;
	while (temp)
	{
		mistakes += count_inversions(temp);
		temp = temp->next;
	}
	len = stack_len(a);
	if (len <= 1)
		return (0.0f);
	total_pairs = len * (len - 1) / 2;
	return (mistakes / total_pairs);
}
