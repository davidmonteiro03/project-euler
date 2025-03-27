/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 07:48:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static void	solve(long long int n)
{
	long long int	solution;
	long long int	i;

	solution = 1;
	i = 1;
	while (i < n)
		solution = utils_lcm(solution, i++);
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
