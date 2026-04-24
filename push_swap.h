/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:00:00 by muarici           #+#    #+#             */
/*   Updated: 2026/04/24 03:45:22 by muarici          ###   ########.fr       */
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
	int				curr_idx;
	int				target_idx;
	struct s_node	*next;
}					t_node;

int					ft_strlen(char *s);
void				free_stack(t_node **stack);
void				free_split(char **split);

t_node				*new_node(int value);
void				add_back(t_node **stack, t_node *new);
void				set_current_indices(t_node *stack);
void				set_target_indices(t_node *stack);
void				set_current_and_target_idx(t_node *stack);

void				sa(t_node **a, int print);
void				sb(t_node **b, int print);
void				ss(t_node **a, t_node **b);
void				pa(t_node **a, t_node **b, int print);
void				pb(t_node **b, t_node **a, int print);

void				ra(t_node **a, int print);
void				rb(t_node **b, int print);
void				rr(t_node **a, t_node **b);
void				rra(t_node **a, int print);
void				rrb(t_node **b, int print);
void				rrr(t_node **a, t_node **b);

int					is_clear(char *str);
int					is_duplicate(t_node *stack, int val);
int					ft_atoi_check(char *str, int *error);
char				**ft_split(char *str);
int					fill_stack(t_node **a, char **split);
void				print_stack(char *name, t_node *stack);
void				rrr(t_node **a, t_node **b);

t_node				*sort_2(t_node *a);
t_node				*sort_3(t_node *a);
t_node				*sort_4(t_node *a, t_node *b);
t_node				*sort_5(t_node *a, t_node *b);
t_node				*simple_sort(t_node *a, t_node *b);
size_t				stack_len(t_node *node);
float				compute_disorder(t_node *a);

#endif
