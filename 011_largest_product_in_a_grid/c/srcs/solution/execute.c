/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 17:01:08 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static int	fwrite_grid(FILE *f, long long int grid[20][20], size_t m, size_t n)
{
	size_t	i;
	size_t	j;
	int		ret;

	if (f == NULL)
		return (EX__BASE);
	i = 0;
	while (i < m)
	{
		j = 0;
		while (j < n)
		{
			ret = fscanf(f, "%lld", &grid[i][j]);
			if (ret != 1)
				return (EX__BASE);
			j++;
		}
		i++;
	}
	return (EX_OK);
}

static long long int	compute_product(long long int grid[20][20], size_t i,
		size_t j, size_t type)
{
	if (type == 0)
		return (grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3]);
	if (type == 1)
		return (grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j]);
	if (type == 2)
		return (grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i
			+ 3][j + 3]);
	return (grid[i][j + 3] * grid[i + 1][j + 2] * grid[i + 2][j + 1] * grid[i
		+ 3][j]);
}

static long long int	find_largest_grid_product(long long int grid[20][20],
		size_t m, size_t n)
{
	size_t			p[3];
	long long int	prods[4];
	long long int	result;

	result = 0;
	p[0] = 0;
	while (p[0] < m - 3)
	{
		p[1] = 0;
		while (p[1] < n - 3)
		{
			p[2] = 0;
			while (p[2] < 4)
			{
				prods[p[2]] = compute_product(grid, p[0], p[1], p[2]);
				if (prods[p[2]] > result)
					result = prods[p[2]];
				p[2]++;
			}
			p[1]++;
		}
		p[0]++;
	}
	return (result);
}

static void	solve(char *filename)
{
	long long int	solution;
	FILE			*f;
	long long int	grid[20][20];
	size_t			m;
	size_t			n;

	solution = 0;
	if (filename == NULL)
		return (g_exit_status = EX__BASE, (void)0);
	f = fopen(filename, "r");
	if (f == NULL)
		return (g_exit_status = EX__BASE, (void)0);
	bzero(grid, sizeof(grid));
	m = sizeof(grid) / sizeof(grid[0]);
	n = sizeof(grid[0]) / sizeof(grid[0][0]);
	if (fwrite_grid(f, grid, m, sizeof(grid[0]) / sizeof(grid[0][0])) != EX_OK)
		return (fclose(f), g_exit_status = EX__BASE, (void)0);
	fclose(f);
	solution = find_largest_grid_product(grid, m, n);
	fprintf(stdout, "Solution for \"%s\": %lld\n", filename, solution);
}

void	solution_execute(t_solution *solution)
{
	if (solution == NULL)
		return ;
	if (solution->argc != 2)
	{
		fprintf(stderr, "usage: %s <n>\n", solution->argv[0]);
		g_exit_status = EX_USAGE;
		return ;
	}
	solve(solution->argv[1]);
}
