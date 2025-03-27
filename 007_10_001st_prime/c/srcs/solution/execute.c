/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 08:53:28 by dcaetano         ###   ########.fr       */
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
	long long int	tmp_n;

	solution = find_next_prime(0);
	tmp_n = n;
	while (--tmp_n > 0)
		solution = find_next_prime(solution + 1);
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
