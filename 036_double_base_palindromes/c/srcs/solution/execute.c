/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/30 16:16:27 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static bool is_palindrome(const char *str)
{
	size_t	i;
	size_t	len;

	if (str == NULL)
		return (false);
	len = strlen(str);
	i = 0;
	while (i < len / 2)
	{
		if (str[i] != str[len - i - 1])
			return (false);
		i++;
	}
	return (true);
}

static void	solve(long long int limit)
{
	mpz_t			solution;
	long long int	i;
	mpz_t			n;
	char			tmp[2][BUFSIZ];

	bzero(tmp, sizeof(tmp));
	mpz_init_set_ui(solution, 0);
	i = 1;
	while (i < limit)
	{
		bzero(tmp[0], sizeof(tmp[0]));
		snprintf(tmp[0], sizeof(tmp[0]) / sizeof(char), "%lld", i);
		mpz_init_set_str(n, tmp[0], 10);
		mpz_get_str(tmp[1], 2, n);
		if (is_palindrome(tmp[0]) == true && is_palindrome(tmp[1]) == true)
			mpz_add(solution, solution, n);
		mpz_clear(n);
		i++;
	}
	gmp_fprintf(stdout, "Solution for %lld: %Zd\n", limit, solution);
	mpz_clear(solution);
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
