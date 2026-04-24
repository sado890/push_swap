/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 03:14:55 by muarici           #+#    #+#             */
/*   Updated: 2026/04/24 03:46:55 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	comp_for_node(t_node *node)
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
	float mistakes = 0;
	size_t len = 0;
	float total_pairs = 0;
	t_node *temp = a;
	while (temp)
	{
		mistakes += comp_for_node(temp);
		temp = temp->next;
	}
	len = stack_len(a);
	if (len <= 1)
		return (0.0f);
	total_pairs = len * (len - 1) / 2;
	return (mistakes / total_pairs);
}