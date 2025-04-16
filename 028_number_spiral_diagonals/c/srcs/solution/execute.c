/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/16 16:52:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static void	alloc_spiral(long long int ***spiral, size_t size)
{
	size_t	m_size;
	size_t	n_size;
	size_t	i;

	if (spiral == NULL || size == 0)
		return ;
	m_size = sizeof(long long int *) * size;
	*spiral = (long long int **)malloc(m_size);
	if (*spiral == NULL)
		return ;
	bzero(*spiral, m_size);
	n_size = sizeof(long long int) * size;
	i = 0;
	while (i < size)
	{
		(*spiral)[i] = (long long int *)malloc(n_size);
		bzero((*spiral)[i++], n_size);
	}
}

static void	move_clock(long long int **spiral, size_t change[3],
		size_t fixed[2], int *dir)
{
	size_t	step[2];

	step[0] = -1;
	while (++step[0] < 2)
	{
		step[1] = -1;
		while (++step[1] < fixed[1])
		{
			if (change[2] > fixed[0] * fixed[0])
				break ;
			if (*dir == 0)
				change[1]++;
			else if (*dir == 1)
				change[0]++;
			else if (*dir == 2)
				change[1]--;
			else
				change[0]--;
			spiral[change[0]][change[1]] = change[2]++;
		}
		*dir = (*dir + 1) % 4;
	}
}

static void	fill_spiral(long long int **spiral, size_t size)
{
	size_t	change[3];
	size_t	fixed[2];
	int		dir;

	if (spiral == NULL || *spiral == NULL || size == 0)
		return ;
	change[0] = size / 2;
	change[1] = size / 2;
	change[2] = 1;
	spiral[change[0]][change[1]] = change[2]++;
	fixed[0] = size;
	fixed[1] = 1;
	dir = 0;
	while (change[2] <= size * size)
	{
		move_clock(spiral, change, fixed, &dir);
		fixed[1]++;
	}
}

static void	solve(long long int size)
{
	long long int	solution;
	long long int	**spiral;
	size_t			i;
	size_t			j;

	solution = 0;
	if (size <= 0 || size % 2 == 0)
		return ;
	alloc_spiral(&spiral, size);
	fill_spiral(spiral, size);
	i = 0;
	while (i < (size_t)size)
	{
		j = 0;
		while (j < (size_t)size)
		{
			solution += (i == j || i == size - j - 1) * spiral[i][j];
			j++;
		}
		if (spiral[i] != NULL)
			free(spiral[i]);
		i++;
	}
	free(spiral);
	fprintf(stdout, "Solution for %lld: %lld\n", size, solution);
}

void	solution_execute(t_solution *solution)
{
	long long int	size;

	if (solution == NULL)
		return ;
	if (solution->argc != 2)
	{
		fprintf(stderr, "usage: %s <size>\n", solution->argv[0]);
		g_exit_status = EX_USAGE;
		return ;
	}
	size = 0;
	if (sscanf(solution->argv[1], "%lld", &size) == -1)
	{
		fprintf(stderr, "%s: error: '%s' is not integer.\n",
			solution->argv[0], solution->argv[1]);
		g_exit_status = EX_DATAERR;
		return ;
	}
	solve(size);
}
