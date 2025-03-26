/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/26 19:03:07 by dcaetano         ###   ########.fr       */
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
