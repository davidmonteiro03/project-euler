/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 15:31:17 by dcaetano         ###   ########.fr       */
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
