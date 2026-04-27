/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:46:40 by muarici           #+#    #+#             */
/*   Updated: 2026/04/27 17:23:26 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cleanup_and_exit(t_node **a, t_info *bench, int status)
{
	if (a && *a)
		free_stack(a);
	if (bench)
		free(bench);
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

static void	set_strategy(char format, t_strategy *strat, t_info *bench)
{
	if (format == 'A' || format == 'N' || format == 'B')
		*strat = ADAPTIVE;
	else if (format == 'S')
		*strat = LOW_DISORDER;
	else if (format == 'M')
		*strat = MEDIUM_DISORDER;
	else
		*strat = HIGH_DISORDER;
	bench->strategy = *strat;
}

int	main(int argc, char **argv)
{
	t_node		*a;
	t_info		*bench;
	t_strategy	strat;
	char		f;
	int			i;

	if (argc < 2)
		return (0);
	a = NULL;
	bench = malloc(sizeof(t_info));
	if (!bench)
		return (1);
	init_main_vars(argv, &f, &i, bench);
	if (f == 'E' || parse_and_fill_all(&a, argc, argv, i) == -1)
		return (cleanup_and_exit(&a, bench, 1));
	set_current_and_target_idx(a);
	bench->disorder = compute_disorder(a);
	set_strategy(f, &strat, bench);
	run_strategy(a, NULL, strat, bench);
	if (bench->bench_mode)
		print_bench(bench);
	return (cleanup_and_exit(&a, bench, 0));
}
