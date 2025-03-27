/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 15:57:34 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static long long int	find_pythagorean_triplet(long long int n)
{
	long long int	a;
	long long int	b;
	long long int	c;

	a = 1;
	while (a <= n)
	{
		b = a + 1;
		while (b <= n)
		{
			c = b + 1;
			while (c <= n)
			{
				if (a * a + b * b == c * c && a + b + c == n)
					return (a * b * c);
				c++;
			}
			b++;
		}
		a++;
	}
	return (0);
}

static void	solve(long long int n)
{
	long long int	solution;

	solution = find_pythagorean_triplet(n);
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
