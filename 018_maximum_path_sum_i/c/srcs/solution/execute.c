/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:53:20 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/01 10:22:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static long long int	ft_max(long long int a, long long int b)
{
	if (a >= b)
		return (a);
	return (b);
}

static long long int	solve_recursive(long long int **triangle, size_t pos[2],
		size_t row, size_t col)
{
	if (pos[1] == col)
		return (0);
	if (pos[0] == row - 1)
		return (triangle[pos[0]][pos[1]]);
	return (triangle[pos[0]][pos[1]] + ft_max(solve_recursive(triangle,
				(size_t [2]){pos[0] + 1, pos[1]}, row, col),
			solve_recursive(triangle, (size_t [2]){pos[0] + 1, pos[1] + 1}, row,
				col)));
}

static void	solve(t_solution *solution)
{
	long long int	result;

	result = solve_recursive(solution->triangle, (size_t [2]){0, 0},
			solution->n_lines, solution->n_lines);
	fprintf(stdout, "Solution for [\"%s\", %zu]: %lld\n", solution->argv[1],
		solution->n_lines, result);
}

void	solution_execute(t_solution *solution)
{
	size_t	i;

	if (solution == NULL)
		return ;
	solve(solution);
	i = 0;
	while (i < solution->n_lines)
	{
		if (solution->triangle[i] != NULL)
			free(solution->triangle[i]);
		i++;
	}
	free(solution->triangle);
}
