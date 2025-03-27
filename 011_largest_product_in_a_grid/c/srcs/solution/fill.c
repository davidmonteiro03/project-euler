/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:51:48 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 17:59:59 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static void	grid_fill(t_solution *solution, char *filename)
{
	FILE	*f;
	size_t	i;
	size_t	j;
	int		ret;

	if (solution == NULL || filename == NULL || g_exit_status != EX_OK)
		return (g_exit_status = EX__BASE, (void)0);
	f = fopen(filename, "r");
	if (f == NULL)
		return (g_exit_status = EX__BASE, (void)0);
	i = 0;
	while (i < solution->m)
	{
		j = 0;
		while (j < solution->n)
		{
			ret = fscanf(f, "%lld", &solution->grid[i][j]);
			if (ret != 1)
				return (fclose(f), g_exit_status = EX__BASE, (void)0);
			j++;
		}
		i++;
	}
	fclose(f);
}

void	solution_fill(t_solution *solution)
{
	if (solution == NULL || g_exit_status != EX_OK)
		return ;
	if (solution->argc != 2)
	{
		fprintf(stderr, "usage: %s <n>\n", solution->argv[0]);
		g_exit_status = EX_USAGE;
		return ;
	}
	grid_fill(solution, solution->argv[1]);
}
