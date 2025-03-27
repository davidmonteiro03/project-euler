/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 15:23:54 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static long long int	get_limit(long long int n)
{
	long long int	limit;

	limit = 1;
	while (n-- > 1)
		limit *= 10;
	return (limit);
}

static long long int	update_solution(long long int solution, long long int i,
		long long int j)
{
	char	buf[BUFSIZ];
	size_t	len;
	bool	palindrome;
	size_t	k;

	bzero(buf, sizeof(buf));
	sprintf(buf, "%lld", i * j);
	len = strlen(buf);
	palindrome = true;
	k = 0;
	while (k < len / 2)
	{
		if (buf[k] != buf[len - k - 1])
		{
			palindrome = false;
			break ;
		}
		k++;
	}
	if (palindrome == true && i * j > solution)
		return (i * j);
	return (solution);
}

static void	solve(long long int n)
{
	long long int	solution;
	long long int	i;
	long long int	j;
	long long int	limit;

	solution = 0;
	i = get_limit(n);
	limit = i * 10;
	while (i < limit)
	{
		j = ++i;
		while (j < limit)
			solution = update_solution(solution, i, j++);
	}
	fprintf(stdout, "Solution for %lld: %lld\n", n, solution);
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
