/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:00:00 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 04:04:54 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ========================= */
/*        STRUCTURES         */
/* ========================= */

typedef struct s_node
{
	int				value;
	int				curr_idx;
	int				target_idx;
	struct s_node	*next;
}	t_node;

typedef enum e_strategy
{
	LOW_DISORDER,
	MEDIUM_DISORDER,
	HIGH_DISORDER
}	t_strategy;

/* ========================= */
/*         UTILS             */
/* ========================= */

int		ft_strlen(char *s);
void	free_stack(t_node **stack);
void	free_split(char **split);

/* ========================= */
/*      STACK CREATION       */
/* ========================= */

t_node	*new_node(int value);
void	add_back(t_node **stack, t_node *new);
size_t	stack_len(t_node *node);

/* ========================= */
/*         PARSING           */
/* ========================= */

int		is_clear(char *str);
int		is_duplicate(t_node *stack, int val);
int		ft_atoi_check(char *str, int *error);
char	**ft_split(char *str);
int		fill_stack(t_node **a, char **split);

/* ========================= */
/*      INDEX / METADATA     */
/* ========================= */

void	set_current_indices(t_node *stack);
void	set_target_indices(t_node *stack);
void	set_current_and_target_idx(t_node *stack);

/* ========================= */
/*        OPERATIONS         */
/* ========================= */

/* swap */
void	sa(t_node **a, int print);
void	sb(t_node **b, int print);
void	ss(t_node **a, t_node **b);

/* push */
void	pa(t_node **a, t_node **b, int print);
void	pb(t_node **b, t_node **a, int print);

/* rotate */
void	ra(t_node **a, int print);
void	rb(t_node **b, int print);
void	rr(t_node **a, t_node **b);

/* reverse rotate */
void	rra(t_node **a, int print);
void	rrb(t_node **b, int print);
void	rrr(t_node **a, t_node **b);

/* ========================= */
/*          SORTING          */
/* ========================= */

t_node	*sort_2(t_node *a);
t_node	*sort_3(t_node *a);
t_node	*sort_4(t_node *a, t_node *b);
t_node	*sort_5(t_node *a, t_node *b);

void	simple_sort(t_node *a, t_node *b);
void	medium_sort(t_node *a, t_node *b);
void	complex_sort(t_node *a, t_node *b);

/* ========================= */
/*        ALGORITHMS         */
/* ========================= */

float	compute_disorder(t_node *a);
void	execute_adaptive_sort(t_node *a, t_node *b);

/* ========================= */
/*         DEBUG             */
/* ========================= */

void	print_stack(char *name, t_node *stack);

#endif