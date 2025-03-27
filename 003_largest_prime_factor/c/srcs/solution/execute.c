/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/26 19:03:18 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static void	solve(long long int n)
{
	long long int	solution;
	long long int	tmp_n;
	long long int	factor;

	solution = 0;
	tmp_n = n;
	while (tmp_n % 2 == 0)
	{
		solution = 2;
		tmp_n /= 2;
	}
	factor = 3;
	while (factor * factor <= tmp_n)
	{
		while (tmp_n % factor == 0)
		{
			solution = factor;
			tmp_n /= factor;
		}
		factor += 2;
	}
	if (tmp_n > 2)
		solution = tmp_n;
	printf("Solution for %lld: %lld\n", n, solution);
}

void	solution_execute(t_solution *solution)
{
	long long int	n;
	int				i;

	if (solution == NULL)
		return ;
	n = 0;
	if (solution->argc < 2)
	{
		scanf("%lld", &n);
		solve(n);
		return ;
	}
	i = 1;
	while (i < solution->argc)
	{
		sscanf(solution->argv[i++], "%lld", &n);
		solve(n);
	}
}
