/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/26 19:02:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static void	solve(long long int n)
{
	long long int	first;
	long long int	second;
	long long int	next;
	long long int	solution;

	solution = 0;
	first = 1;
	second = 1;
	next = first + second;
	while (first < n)
	{
		solution += first * (first % 2 == 0);
		first = second;
		second = next;
		next = first + second;
	}
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
