/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:28:50 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/17 08:37:51 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static void	solve(long long int **spiral, size_t m, size_t n)
{
	long long int	solution;
	size_t			i;
	size_t			j;

	if (spiral == NULL || m == 0 || n == 0 || m % 2 == 0 || n % 2 == 0
		|| m != n)
		return ;
	solution = 0;
	i = 0;
	while (i < m)
	{
		j = 0;
		while (j < n)
		{
			solution += spiral[i][j] * (i == j || i == n - j - 1);
			j++;
		}
		i++;
	}
	fprintf(stdout, "Solution for %zu by %zu: %lld\n", m, n, solution);
}

void	solution_execute(t_solution *solution)
{
	size_t	i;

	if (solution == NULL || solution->spiral == NULL || solution->m == 0
		|| solution->n == 0 || solution->m % 2 == 0 || solution->n % 2 == 0
		|| solution->m != solution->n)
		return ;
	solve(solution->spiral, solution->m, solution->n);
	i = 0;
	while (i < solution->m)
	{
		if (solution->spiral[i] != NULL)
		{
			free(solution->spiral[i]);
			solution->spiral[i] = NULL;
		}
		i++;
	}
	free(solution->spiral);
	solution->spiral = NULL;
}
