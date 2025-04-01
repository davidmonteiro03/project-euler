/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/01 17:00:05 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static long long int	sum_divisors(long long int n)
{
	long long int	result;
	long long int	i;

	result = 1;
	i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
		{
			result += i;
			if (i != n / i)
				result += n / i;
		}
		i++;
	}
	return (result);
}

static bool	is_abundant(long long int n)
{
	return (sum_divisors(n) > n);
}

static bool	is_sum_of_abundants(long long int n)
{
	long long int	i;

	i = 12;
	while (i <= n / 2)
	{
		if (is_abundant(i) && is_abundant(n - i))
			return (true);
		i++;
	}
	return (false);
}

static void	solve(long long int n)
{
	long long int	solution;
	long long int	i;

	solution = 0;
	i = 1;
	while (i <= n)
	{
		if (!is_sum_of_abundants(i))
			solution += i;
		i++;
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
