/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 10:16:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static void	solve(long long int n)
{
	long long int	solution;
	size_t			i;
	size_t			j;
	long long int	prod;

	solution = 0;
	i = 0;
	while (i < strlen(_1000_DIGIT_NUMBER) - n)
	{
		prod = 1;
		j = i;
		while (j < i + n)
			prod *= _1000_DIGIT_NUMBER[j++] - '0';
		if (prod > solution)
			solution = prod;
		i++;
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
