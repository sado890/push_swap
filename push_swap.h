/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:00:00 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 17:18:47 by muarici          ###   ########.fr       */
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

typedef enum e_strategy
{
	LOW_DISORDER,
	MEDIUM_DISORDER,
	HIGH_DISORDER,
	ADAPTIVE
}					t_strategy;

typedef struct s_info
{
	int				bench_mode;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
	float			disorder;
	t_strategy		strategy;
	char			*notation;
}					t_info;

void				*ft_memset(void *s, int c, size_t n);
int					ft_strlen(char *s);
void				free_stack(t_node **stack);
void				free_split(char **split);

t_node				*new_node(int value);
void				add_back(t_node **stack, t_node *new);
size_t				stack_len(t_node *node);

int					is_clear(char *str);
int					is_duplicate(t_node *stack, int val);
int					ft_atoi_check(char *str, int *error);
char				**ft_split(char *str);
int					fill_stack(t_node **a, char **split);

void				set_current_indices(t_node *stack);
void				set_target_indices(t_node *stack);
void				set_current_and_target_idx(t_node *stack);

void				sa(t_node **a, int print, t_info *bench);
void				sb(t_node **b, int print, t_info *bench);
void				ss(t_node **a, t_node **b, t_info *bench);

void				pa(t_node **a, t_node **b, int print, t_info *bench);
void				pb(t_node **b, t_node **a, int print, t_info *bench);

void				ra(t_node **a, int print, t_info *bench);
void				rb(t_node **b, int print, t_info *bench);
void				rr(t_node **a, t_node **b, t_info *bench);

void				rra(t_node **a, int print, t_info *bench);
void				rrb(t_node **b, int print, t_info *bench);
void				rrr(t_node **a, t_node **b, t_info *bench);

t_node				*sort_2(t_node *a, t_info *bench);
t_node				*sort_3(t_node *a, t_info *bench);
t_node				*sort_4(t_node *a, t_node *b, t_info *bench);
t_node				*sort_5(t_node *a, t_node *b, t_info *bench);
void				simple_sort(t_node *a, t_node *b, t_info *bench);
void				medium_sort(t_node *a, t_node *b, t_info *bench);
void				complex_sort(t_node *a, t_node *b, t_info *bench);

int					handle_small_size(t_node *a, t_node *b, int size,
						t_info *bench);

float				compute_disorder(t_node *a);
void				execute_adaptive_sort(t_node *a, t_node *b, t_info *bench);
void				run_strategy(t_node *a, t_node *b, t_strategy strat,
						t_info *bench);

void				print_stack(char *name, t_node *stack);
void				print_bench(t_info *bench);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
