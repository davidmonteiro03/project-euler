/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/31 07:45:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static void	solve(long long int base, long long int exp)
{
	mpz_t	solution;
	mpz_t	pow_value;
	char	pow_str[BUFSIZ];
	size_t	i;
	size_t	len;

	mpz_init(solution);
	mpz_init(pow_value);
	mpz_ui_pow_ui(pow_value, base, exp);
	bzero(pow_str, sizeof(pow_str));
	gmp_sprintf(pow_str, "%Zd", pow_value);
	len = strlen(pow_str);
	i = 0;
	while (i < len)
		mpz_add_ui(solution, solution, pow_str[i++] - '0');
	gmp_fprintf(stdout, "Solution for [%lld, %lld]: %Zd\n", base, exp, solution);
	mpz_clear(pow_value);
	mpz_clear(solution);
}

void	solution_execute(t_solution *solution)
{
	long long int	base;
	long long int	exp;
	int				ret_base;
	int				ret_exp;

	if (solution == NULL)
		return ;
	if (solution->argc != 3)
	{
		fprintf(stderr, "usage: %s <base> <exp>\n", solution->argv[0]);
		g_exit_status = EX_USAGE;
		return ;
	}
	base = 0;
	exp = 0;
	ret_base = sscanf(solution->argv[1], "%lld", &base);
	ret_exp = sscanf(solution->argv[2], "%lld", &exp);
	if (ret_base == -1 || ret_exp == -1)
	{
		fprintf(stderr, "%s: error: '%s' and '%s' are not both integers.\n",
			solution->argv[0], solution->argv[1], solution->argv[2]);
		g_exit_status = EX_DATAERR;
		return ;
	}
	solve(base, exp);
}
