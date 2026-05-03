/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:46:40 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 19:45:18 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	parse_flag(char *arg)
{
	if (arg[0] != '-' || arg[1] != '-')
		return ('N');
	if (ft_strncmp(arg, "--bench", 7) == 0)
		return ('B');
	else if (ft_strncmp(arg, "--simple", 8) == 0)
		return ('S');
	else if (ft_strncmp(arg, "--medium", 8) == 0)
		return ('M');
	else if (ft_strncmp(arg, "--complex", 9) == 0)
		return ('C');
	else if (ft_strncmp(arg, "--adaptive", 10) == 0)
		return ('A');
	return ('E');
}

int	cleanup_and_exit(t_node **a, t_node **b, int status)
{
	if (a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
	if (status == 1)
		write(2, "Error\n", 6);
	return (status);
}

static void	init_main_vars(char **argv, char *f, int *i, t_info *bench)
{
	*f = parse_flag(argv[1]);
	*i = 1;
	if (*f == 'B' || (*f != 'N' && *f != 'E'))
		*i = 2;
	ft_memset(bench, 0, sizeof(t_info));
	if (*f == 'B')
		bench->bench_mode = 1;
}

static void	set_strategy(char format, t_info *bench)
{
	if (format == 'A' || format == 'N' || format == 'B')
		bench->strategy = ADAPTIVE;
	else if (format == 'S')
		bench->strategy = LOW_DISORDER;
	else if (format == 'M')
		bench->strategy = MEDIUM_DISORDER;
	else
		bench->strategy = HIGH_DISORDER;
}

int	main(int argc, char **argv)
{
	t_node		*a;
	t_node		*b_stack;
	t_info		bench;
	char		f;
	int			i;

	if (argc < 2)
		return (0);
	a = NULL;
	b_stack = NULL;
	init_main_vars(argv, &f, &i, &bench);
	if (f == 'E' || parse_and_fill_all(&a, argc, argv, i) == -1)
		return (cleanup_and_exit(&a, &b_stack, 1));
	set_current_and_target_idx(a);
	bench.disorder = compute_disorder(a);
	set_strategy(f, &bench);
	run_strategy(&a, &b_stack, bench.strategy, &bench);
	if (bench.bench_mode)
		print_bench(&bench);
	return (cleanup_and_exit(&a, &b_stack, 0));
}
