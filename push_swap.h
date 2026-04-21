/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:00:00 by muarici           #+#    #+#             */
/*   Updated: 2026/04/16 18:04:39 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

/* --- Utils --- */
int		ft_strlen(char *s);
void	free_stack(t_node **stack);
void	free_split(char **split);

/* --- Node Operations --- */
t_node	*new_node(int value);
void	add_back(t_node **stack, t_node *new);

/* --- Stack Operations (Swap & Push) --- */
void	sa(t_node **a, int print);
void	sb(t_node **b, int print);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b, int print);
void	pb(t_node **b, t_node **a, int print);

/* --- Rotate Operations --- */
void	ra(t_node **a, int print);
void	rb(t_node **b, int print);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a, int print);
void	rrb(t_node **b, int print);
void	rrr(t_node **a, t_node **b);

/* --- Parsing & Validation --- */
int		is_clear(char *str);
int		is_duplicate(t_node *stack, int val);
int		ft_atoi_check(char *str, int *error);
char	**ft_split(char *str);
int		get_to_nodes(t_node **a, char **split);
void	print_stack(char *name, t_node *stack);
void	rrr(t_node **a, t_node **b);

#endif
