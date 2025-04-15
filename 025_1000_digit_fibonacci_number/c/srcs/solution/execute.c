/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/15 15:07:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static size_t	get_num_digits(mpz_t n)
{
	char	buf[BUFSIZ];

	if (n == NULL)
		return (0);
	bzero(buf, sizeof(buf));
	gmp_sprintf(buf, "%Zd", n);
	return (strlen(buf));
}

static void	solve(long long int n)
{
	long long int	solution;
	mpz_t			prev_prev;
	mpz_t			prev;
	mpz_t			curr;
	size_t			len;

	solution = 2;
	mpz_init_set_ui(prev_prev, 1);
	mpz_init_set_ui(prev, 1);
	mpz_init_set_ui(curr, 1);
	while (true)
	{
		len = get_num_digits(curr);
		if (len >= (size_t)n)
			break ;
		mpz_add(curr, prev_prev, prev);
		mpz_set(prev_prev, prev);
		mpz_set(prev, curr);
		solution++;
	}
	gmp_fprintf(stdout, "Solution for %lld: %lld\n", n, solution);
	mpz_clear(curr);
	mpz_clear(prev);
	mpz_clear(prev_prev);
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
