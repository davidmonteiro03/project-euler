/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/30 12:16:35 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static void	factorial_sum(mpz_t z[3], long long int i)
{
	char	tmp[BUFSIZ];
	size_t	k;

	bzero(tmp, sizeof(tmp));
	snprintf(tmp, sizeof(tmp) / sizeof(char), "%lld", i);
	mpz_init_set_ui(z[0], i);
	mpz_init_set_ui(z[1], 0);
	k = 0;
	while (k < strlen(tmp))
	{
		mpz_init_set_ui(z[2], 1);
		mpz_fac_ui(z[2], (long long int)(tmp[k++] - '0'));
		mpz_add(z[1], z[1], z[2]);
		mpz_clear(z[2]);
	}
}

static void	numbers_sum(mpz_t solution, long long int i)
{
	mpz_t	z[3];

	bzero(z, sizeof(z));
	factorial_sum(z, i);
	if (mpz_cmp(z[0], z[1]) == 0)
		mpz_add(solution, solution, z[0]);
	mpz_clear(z[1]);
	mpz_clear(z[0]);
}

static void	solve(long long int limit)
{
	mpz_t			solution;
	long long int	i;

	mpz_init_set_ui(solution, 0);
	i = 10;
	while (i <= limit && i <= 100000)
		numbers_sum(solution, i++);
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
