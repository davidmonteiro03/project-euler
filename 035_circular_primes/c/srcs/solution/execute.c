/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/30 14:41:08 by dcaetano         ###   ########.fr       */
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

static void	rotate_str(char *str)
{
	char	first;
	size_t	len;

	if (str == NULL || *str == '\0' || *(str + 1) == '\0')
		return ;
	first = str[0];
	len = strlen(str);
	memmove(str, str + 1, sizeof(char) * (len + 1));
	str[len - 1] = first;
}

static bool	check_circular_prime(long long int n)
{
	char			tmp[BUFSIZ];
	size_t			k;
	long long int	tmp_n;

	bzero(tmp, sizeof(tmp));
	snprintf(tmp, sizeof(tmp) / sizeof(char), "%lld", n);
	k = 0;
	while (k < strlen(tmp))
	{
		sscanf(tmp, "%lld", &tmp_n);
		if (is_prime(tmp_n) == false)
			return (false);
		rotate_str(tmp);
		k++;
	}
	return (true);
}

static void	solve(long long int limit)
{
	long long int	solution;
	long long int	i;

	solution = 0;
	i = 1;
	while (i < limit)
		solution += check_circular_prime(i++);
	fprintf(stdout, "Solution for %lld: %lld\n", limit, solution);
}

void	solution_execute(t_solution *solution)
{
	long long int	limit;
	int				ret;

	if (solution == NULL)
		return ;
	if (solution->argc != 2)
	{
		fprintf(stderr, "usage: %s <limit>\n", solution->argv[0]);
		g_exit_status = EX_USAGE;
		return ;
	}
	limit = 0;
	ret = sscanf(solution->argv[1], "%lld", &limit);
	if (ret == -1)
	{
		fprintf(stderr, "%s: error: '%s' is not an integer.\n",
			solution->argv[0], solution->argv[1]);
		g_exit_status = EX_DATAERR;
		return ;
	}
	solve(limit);
}
