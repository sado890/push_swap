/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:15:00 by muarici           #+#    #+#             */
/*   Updated: 2026/04/16 18:12:58 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_split(char *str, char **res)
{
	int	i;
	int	k;
	int	j;
	int	l;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
		{
			j = i;
			while (str[j] && str[j] != ' ')
				j++;
			res[k] = malloc(j - i + 1);
			l = 0;
			while (i < j)
				res[k][l++] = str[i++];
			res[k][l] = '\0';
			k++;
		}
	}
	res[k] = NULL;
}

char	**ft_split(char *str)
{
	char	**res;

	res = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	if (!res)
		return (NULL);
	fill_split(str, res);
	return (res);
}
