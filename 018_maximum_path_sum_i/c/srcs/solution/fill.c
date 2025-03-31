/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:51:48 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/31 10:39:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static void	triangle_alloc(t_solution *solution)
{
	size_t	i;

	if (solution == NULL)
		return ;
	solution->triangle = (long long int **)calloc(sizeof(long long int *),
			solution->n_lines);
	i = 0;
	while (i < solution->n_lines)
	{
		solution->triangle[i] = (long long int *)calloc(sizeof(long long int),
				i + 1);
		i++;
	}
}

static void	triangle_fill(t_solution *solution, char *filename)
{
	FILE	*f;
	size_t	i;
	size_t	j;

	if (solution == NULL || filename == NULL || g_exit_status != EX_OK)
		return (g_exit_status = EX__BASE, (void)0);
	f = fopen(filename, "r");
	if (f == NULL)
		return (g_exit_status = EX__BASE, (void)0);
	i = 0;
	while (i < solution->n_lines)
	{
		j = 0;
		while (j < i + 1)
		{
			if (fscanf(f, "%lld", &solution->triangle[i][j]) != 1)
				return (fclose(f), g_exit_status = EX__BASE, (void)0);
			j++;
		}
		i++;
	}
	fclose(f);
}

void	solution_fill(t_solution *solution)
{
	if (solution == NULL || g_exit_status != EX_OK)
		return ;
	if (solution->argc != 3)
	{
		fprintf(stderr, "usage: %s <filename> <num_lines>\n",
			solution->argv[0]);
		g_exit_status = EX_USAGE;
		return ;
	}
	if (sscanf(solution->argv[2], "%zu", &solution->n_lines) != 1)
	{
		fprintf(stderr, "%s: error: '%s' is not an integer.\n",
			solution->argv[0], solution->argv[2]);
		g_exit_status = EX_USAGE;
		return ;
	}
	triangle_alloc(solution);
	triangle_fill(solution, solution->argv[1]);
}
