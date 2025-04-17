/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/17 14:09:49 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static long long int	count_recursive(long long int *coins, size_t n,
		long long int sum)
{
	if (sum == 0)
		return (1);
	if (sum < 0 || n == 0)
		return (0);
	return (count_recursive(coins, n, sum - coins[n - 1])
		+ count_recursive(coins, n - 1, sum));
}

static void	solve(long long int sum)
{
	static const long long int	coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
	long long int				solution;

	solution = count_recursive((long long int *)coins, sizeof(coins)
			/ sizeof(long long int), sum);
	fprintf(stdout, "Solution for %lld: %lld\n", sum, solution);
}

void	solution_execute(t_solution *solution)
{
	long long int	sum;
	int				ret;

	if (solution == NULL)
		return ;
	if (solution->argc != 2)
	{
		fprintf(stderr, "usage: %s <sum>\n", solution->argv[0]);
		g_exit_status = EX_USAGE;
		return ;
	}
	sum = 0;
	ret = sscanf(solution->argv[1], "%lld", &sum);
	if (ret == -1)
	{
		fprintf(stderr, "%s: error: '%s' is not an integer.\n",
			solution->argv[0], solution->argv[1]);
		g_exit_status = EX_DATAERR;
		return ;
	}
	solve(sum);
}
