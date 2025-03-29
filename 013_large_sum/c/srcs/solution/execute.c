/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 23:19:22 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/29 00:17:27 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static long long int	extract_first_10_digits_from_sum(t_solution *solution)
{
	long long int	result;
	size_t			i;
	mpz_t			sum;
	mpz_t			tmp;
	char			sum_str[BUFSIZ];

	if (solution == NULL)
		return (0);
	result = 0;
	mpz_init_set_si(sum, 0);
	i = 0;
	while (i < solution->length)
	{
		mpz_init_set_str(tmp, solution->nums[i], 10);
		mpz_add(sum, sum, tmp);
		mpz_clear(tmp);
		i++;
	}
	gmp_sprintf(sum_str, "%Zd", sum);
	sscanf(sum_str, "%10lld", &result);
	mpz_clear(sum);
	return (result);
}

void	solution_execute(t_solution *solution)
{
	long long int	result;

	if (solution == NULL || g_exit_status != EX_OK)
		return ;
	result = extract_first_10_digits_from_sum(solution);
	fprintf(stdout, "Solution for \"%s\": %lld\n", solution->argv[1], result);
}
