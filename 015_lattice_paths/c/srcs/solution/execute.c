/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/29 16:05:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static void	solve(long long int k, long long int n)
{
	mpz_t	solution;
	mpz_t	fact_1;
	mpz_t	fact_2;
	mpz_t	fact_3;

	mpz_init(solution);
	mpz_init(fact_1);
	mpz_init(fact_2);
	mpz_init(fact_3);
	mpz_fac_ui(fact_1, k + n);
	mpz_fac_ui(fact_2, k);
	mpz_fac_ui(fact_3, n);
	mpz_set(solution, fact_1);
	mpz_div(solution, solution, fact_2);
	mpz_div(solution, solution, fact_3);
	gmp_fprintf(stdout, "Solution for [%lld, %lld]: %Zd\n", k, n, solution);
	mpz_clear(fact_3);
	mpz_clear(fact_2);
	mpz_clear(fact_1);
	mpz_clear(solution);
}

void	solution_execute(t_solution *solution)
{
	long long int	k;
	long long int	n;
	int				ret_k;
	int				ret_n;

	if (solution == NULL)
		return ;
	if (solution->argc != 3)
	{
		fprintf(stderr, "usage: %s <k> <n>\n", solution->argv[0]);
		g_exit_status = EX_USAGE;
		return ;
	}
	k = 0;
	n = 0;
	ret_k = sscanf(solution->argv[1], "%lld", &k);
	ret_n = sscanf(solution->argv[2], "%lld", &n);
	if (ret_k == -1 || ret_n == -1)
	{
		fprintf(stderr, "%s: error: '%s' and '%s' are not both integers.\n",
			solution->argv[0], solution->argv[1], solution->argv[2]);
		g_exit_status = EX_DATAERR;
		return ;
	}
	solve(k, n);
}
