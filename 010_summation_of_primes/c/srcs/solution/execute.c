/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 16:03:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static long long int	find_next_prime(long long int n)
{
	long long int	i;

	if (n <= 1)
		return (find_next_prime(n + 1));
	if (n <= 3)
		return (n);
	if (n % 2 == 0 || n % 3 == 0)
		return (find_next_prime(n + 1));
	i = 5;
	while (i * i <= n && i * i > 0)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return (find_next_prime(n + 1));
		i += 6;
	}
	return (n);
}

static void	solve(long long int n)
{
	long long int	solution;
	long long int	next_prime;

	solution = 0;
	next_prime = find_next_prime(0);
	while (next_prime < n)
	{
		solution += next_prime;
		next_prime = find_next_prime(next_prime + 1);
	}
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
