/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/05/19 15:44:44 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static bool	is_prime(long long int n)
{
	long long int	i;

	if (n <= 1)
		return (false);
	i = 2;
	while (i * i <= n)
		if (n % i++ == 0)
			return (false);
	return (true);
}

static size_t	num_len(const long long int n)
{
	char	buf[BUFSIZ];

	bzero(buf, sizeof(buf));
	snprintf(buf, sizeof(buf) / sizeof(char), "%lld", n);
	return (strlen(buf));
}

static bool	is_truncable_prime(const long long int n)
{
	size_t			n_len;
	size_t			i;
	long long int	n_pow;

	if (n < 10 || is_prime(n) == false)
		return (false);
	n_len = num_len(n);
	i = 0;
	while (i < n_len)
	{
		n_pow = (long long int)pow(10., (double)(n_len - i++));
		if (is_prime(n % n_pow) == false)
			return (false);
	}
	i = 0;
	while (i < n_len)
	{
		n_pow = (long long int)pow(10., (double)i++);
		if (is_prime(n / n_pow) == false)
			return (false);
	}
	return (true);
}

static void	solve(long long int n)
{
	long long int	solution;
	size_t			count;
	long long int	i;

	solution = 0;
	if (n < 0)
		return ;
	count = 0;
	i = 1;
	while (count < (size_t)n)
	{
		if (is_truncable_prime(i) == true)
		{
			count++;
			solution += i;
		}
		i++;
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
