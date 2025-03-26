/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/26 19:56:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static void	solve(long long int start, long long int end)
{
	long long int	solution;
	long long int	i;

	i = start;
	solution = 1;
	while (i < end)
		solution = ft_lcm(solution, ++i);
	printf("Solution for [%lld, %lld]: %lld\n", start, end, solution);
}

static long long int	read_helper(t_solution *solution, int i,
		long long int value)
{
	if (i < solution->argc)
		sscanf(solution->argv[i], "%lld", &value);
	else
		scanf("%lld", &value);
	return (value);
}

void	solution_execute(t_solution *solution)
{
	long long int	start;
	long long int	end;
	int				i;

	if (solution == NULL)
		return ;
	i = 1;
	while (i < solution->argc)
	{
		start = read_helper(solution, i++, start);
		end = read_helper(solution, i++, end);
		solve(start, end);
	}
}
