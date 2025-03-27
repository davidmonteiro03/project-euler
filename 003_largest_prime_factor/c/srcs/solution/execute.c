/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 15:17:18 by dcaetano         ###   ########.fr       */
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
	fprintf(stdout, "Solution for %lld: %lld\n", n, solution);
}

void	solution_execute(t_solution *solution)
{
	long long int	n;
	int				ret;

	if (solution == NULL)
		return ;
	if (solution->argc != 2)
	{
		fprintf(stderr, "usage: %s <n>\n", solution->argv[0]);
		g_exit_status = EX_USAGE;
		return ;
	}
	n = 0;
	ret = sscanf(solution->argv[1], "%lld", &n);
	if (ret == -1)
	{
		fprintf(stderr, "%s: error: '%s' is not an integer.\n",
			solution->argv[0], solution->argv[1]);
		g_exit_status = EX_DATAERR;
		return ;
	}
	solve(n);
}
