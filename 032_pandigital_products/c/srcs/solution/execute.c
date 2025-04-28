/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/28 12:26:52 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static int	charcmp(const void *a, const void *b)
{
	return (*(const char *)a - *(const char *)b);
}

static char	*compute_digits(long long int n)
{
	char			*result;
	const size_t	len = (size_t)n;
	const size_t	size = sizeof(char) * (len + 1);
	size_t			i;

	if (n < 1 || n > 9 || len == 0 || size == 0)
		return (NULL);
	result = (char *)malloc(size);
	if (result == NULL)
		return (NULL);
	bzero(result, size);
	i = -1;
	while (++i < len)
		result[i] = (char)(i + 1) + '0';
	return (result);
}

static void	check_pandigital(long long int n, long long int *solution,
		t_help *h)
{
	long long int	m[2];

	if (n < 1 || n > 9 || solution == NULL || h == NULL || h->ds == NULL)
		return ;
	m[0] = 0;
	while (++m[0] < h->l)
	{
		m[1] = 0;
		while (++m[1] < h->l)
		{
			bzero(h->r, sizeof(h->r));
			snprintf(h->r, sizeof(h->r) / sizeof(char), "%lld%lld%lld", m[0],
				m[1], m[0] * m[1]);
			if (strlen(h->r) != (size_t)n)
				continue ;
			qsort(h->r, strlen(h->r), sizeof(char), &charcmp);
			if (strcmp(h->r, h->ds) != 0)
				continue ;
			if (h->u[m[0] * m[1] - 1] == true)
				continue ;
			h->u[m[0] * m[1] - 1] = true;
			*solution += m[0] * m[1];
		}
	}
}

static void	solve(long long int n)
{
	long long int	solution;
	size_t			size;
	t_help			h;

	solution = 0;
	bzero(&h, sizeof(h));
	h.l = (long long int)pow(10, n / 2);
	size = sizeof(bool) * (size_t)h.l;
	if (n < 1 || n > 9 || h.l <= 0 || size == 0)
		return ;
	h.u = (bool *)malloc(size);
	if (h.u == NULL)
		return ;
	bzero(h.u, size);
	h.ds = compute_digits(n);
	if (h.ds == NULL)
		return (free(h.u), (void)0);
	check_pandigital(n, &solution, &h);
	fprintf(stdout, "Solution for %lld: %lld\n", n, solution);
	free(h.ds);
	free(h.u);
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
