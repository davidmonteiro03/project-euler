/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 11:40:47 by dcaetano         ###   ########.fr       */
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
