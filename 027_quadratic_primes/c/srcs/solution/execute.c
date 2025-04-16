/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/16 14:46:08 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static bool	is_prime(long long int n)
{
	long long int	i;

	if (n <= 1)
		return (false);
	i = 2;
	while (i * i <= n)
		if (n % i++ == 0)
			return (false);
	return (true);
}

static void	solve(long long int limit)
{
	long long int	solution;
	long long int	i[3];
	long long int	o[3];

	i[0] = -limit;
	o[0] = -limit;
	o[1] = -limit;
	o[2] = -limit;
	while (++i[0] < limit)
	{
		i[1] = -limit - 1;
		while (++i[1] <= limit)
		{
			i[2] = 0;
			while (true)
			{
				if (is_prime(i[2] * i[2] + i[0] * i[2] + i[1]) == false)
					break ;
				i[2]++;
			}
			if (i[2] > o[2])
				memcpy(o, i, sizeof(o));
		}
	}
	fprintf(stdout, "Solution for %lld: %lld\n", limit, solution = o[0] * o[1]);
}

void	solution_execute(t_solution *solution)
{
	long long int	limit;

	if (solution == NULL)
		return ;
	if (solution->argc != 2)
	{
		fprintf(stderr, "usage: %s <limit>\n", solution->argv[0]);
		g_exit_status = EX_USAGE;
		return ;
	}
	limit = 0;
	if (sscanf(solution->argv[1], "%lld", &limit) == -1)
	{
		fprintf(stderr, "%s: error: '%s' is not both integers.\n",
			solution->argv[0], solution->argv[1]);
		g_exit_status = EX_DATAERR;
		return ;
	}
	solve(limit);
}
