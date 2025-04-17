/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 07:25:14 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/17 08:48:45 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static void	alloc_spiral(t_solution *solution, long long int m, long long int n)
{
	size_t	m_size;
	size_t	n_size;
	size_t	i;

	if (solution == NULL || m <= 0 || n <= 0 || m % 2 == 0 || n % 2 == 0
		|| m != n)
		return ;
	solution->m = (size_t)m;
	solution->n = (size_t)n;
	m_size = sizeof(long long int *) * solution->m;
	solution->spiral = (long long int **)malloc(m_size);
	if (solution->spiral == NULL)
		return ;
	bzero(solution->spiral, m_size);
	n_size = sizeof(long long int) * solution->n;
	i = 0;
	while (i < solution->m)
	{
		solution->spiral[i] = (long long int *)malloc(n_size);
		bzero(solution->spiral[i++], n_size);
	}
}

static void	move_clock(t_solution *solution, t_help *help)
{
	size_t	s;
	size_t	step;

	s = -1;
	while (++s < 2)
	{
		step = -1;
		while (++step < help->s)
		{
			if (help->c > solution->m * solution->n)
				break ;
			if (help->d == 0)
				help->y++;
			else if (help->d == 1)
				help->x++;
			else if (help->d == 2)
				help->y--;
			else
				help->x--;
			solution->spiral[help->x][help->y] = help->c++;
		}
		help->d = (help->d + 1) % 4;
	}
}

static void	fill_spiral(t_solution *solution)
{
	t_help	help;

	if (solution == NULL || solution->spiral == NULL || solution->m == 0
		|| solution->n == 0 || solution->m % 2 == 0 || solution->n % 2 == 0
		|| solution->m != solution->n)
		return ;
	help = (t_help){.x = solution->m / 2, .y = solution->n / 2, .d = 0, .c = 1,
		.s = 1};
	solution->spiral[help.x][help.y] = help.c++;
	while (help.c <= solution->m * solution->n)
	{
		move_clock(solution, &help);
		help.s++;
	}
}

void	solution_fill(t_solution *solution)
{
	long long int	m;
	long long int	n;

	if (solution == NULL || g_exit_status != EX_OK)
		return ;
	if (solution->argc != 3)
	{
		fprintf(stderr, "usage: %s <m> <n>\n", solution->argv[0]);
		g_exit_status = EX_USAGE;
		return ;
	}
	m = 0;
	n = 0;
	if (sscanf(solution->argv[1], "%lld", &m) != 1 || sscanf(solution->argv[2],
			"%lld", &n) != 1)
	{
		fprintf(stderr, "%s: error: '%s' and '%s' are not both integers.\n",
			solution->argv[0], solution->argv[1], solution->argv[2]);
		g_exit_status = EX_DATAERR;
		return ;
	}
	alloc_spiral(solution, m, n);
	fill_spiral(solution);
}
