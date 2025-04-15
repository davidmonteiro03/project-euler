/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/15 11:15:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static long long int	ft_fact(long long int n)
{
	if (n <= 0)
		return (1);
	return (n * ft_fact(n - 1));
}

static void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	next_permutation(char *set, long long int size)
{
	long long int	i;
	long long int	j;
	long long int	start;
	long long int	end;

	if (set == NULL || size <= 1)
		return ;
	i = size - 2;
	while (i >= 0 && set[i] >= set[i + 1])
		i--;
	if (i < 0)
		return ;
	j = size - 1;
	while (set[j] <= set[i])
		j--;
	ft_swap(&set[i], &set[j]);
	start = i + 1;
	end = size - 1;
	while (start < end)
		ft_swap(&set[start++], &set[end--]);
}

static void	solve(long long int n, long long int pos)
{
	char			*solution;
	size_t			size;
	long long int	i;
	long long int	limit;

	size = sizeof(char) * (n + 1);
	solution = (char *)malloc(size);
	limit = ft_fact(n);
	if (solution == NULL)
		return ;
	bzero(solution, size);
	i = 0;
	while (i < n)
	{
		solution[i] = i + '0';
		i++;
	}
	i = 0;
	while (i < limit && i < pos - 1)
	{
		next_permutation(solution, n);
		i++;
	}
	fprintf(stdout, "Solution for %lld at %lld: %s\n", n, pos, solution);
	free(solution);
}

void	solution_execute(t_solution *solution)
{
	long long int	n;
	long long int	pos;

	if (solution == NULL)
		return ;
	if (solution->argc != 3)
	{
		fprintf(stderr, "usage: %s <n> <pos>\n", solution->argv[0]);
		g_exit_status = EX_USAGE;
		return ;
	}
	n = 0;
	pos = 0;
	if (sscanf(solution->argv[1], "%lld", &n) == -1 || sscanf(solution->argv[2],
			"%lld", &pos) == -1)
	{
		fprintf(stderr, "%s: error: '%s' and '%s' are not both integers.\n",
			solution->argv[0], solution->argv[1], solution->argv[2]);
		g_exit_status = EX_DATAERR;
		return ;
	}
	solve(n, pos);
}
