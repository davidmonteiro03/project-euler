/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/17 12:49:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static int	custom_mpz_compare(const void *a, const void *b)
{
	return (mpz_cmp(*(mpz_t *)a, *(mpz_t *)b));
}

static mpz_t	*alloc_powers(long long int start, long long int end)
{
	mpz_t			*powers;
	size_t			size;
	size_t			i;
	long long int	a;
	long long int	b;

	if (end < start)
		return (NULL);
	size = sizeof(mpz_t) * ((end - start + 1) * (end - start + 1));
	powers = (mpz_t *)malloc(size);
	if (powers == NULL)
		return (NULL);
	bzero(powers, size);
	i = 0;
	a = start - 1;
	while (++a <= end)
	{
		b = start - 1;
		while (++b <= end)
		{
			mpz_init(powers[i]);
			mpz_ui_pow_ui(powers[i++], a, b);
		}
	}
	return (powers);
}

static void	solve(long long int start, long long int end)
{
	size_t	solution;
	size_t	len;
	mpz_t	*powers;
	size_t	i;

	solution = 0;
	if (end < start)
		return ;
	len = (end - start + 1) * (end - start + 1);
	powers = alloc_powers(start, end);
	qsort(powers, len, sizeof(*powers), custom_mpz_compare);
	solution = len;
	i = 0;
	while (i < len - 1)
	{
		if (mpz_cmp(powers[i], powers[i + 1]) == 0)
			solution--;
		i++;
	}
	i = 0;
	while (i < len)
		mpz_clear(powers[i++]);
	free(powers);
	fprintf(stdout, "Solution for [%lld, %lld]: %zu\n", start, end, solution);
}

void	solution_execute(t_solution *solution)
{
	long long int	start;
	long long int	end;

	if (solution == NULL)
		return ;
	if (solution->argc != 3)
	{
		fprintf(stderr, "usage: %s <start> <end>\n", solution->argv[0]);
		g_exit_status = EX_USAGE;
		return ;
	}
	start = 0;
	end = 0;
	if (sscanf(solution->argv[1], "%lld", &start) != 1
		|| sscanf(solution->argv[2], "%lld", &end) != 1)
	{
		fprintf(stderr, "%s: error: '%s' and '%s' are not both integers.\n",
			solution->argv[0], solution->argv[1], solution->argv[2]);
		g_exit_status = EX_DATAERR;
		return ;
	}
	solve(start, end);
}
