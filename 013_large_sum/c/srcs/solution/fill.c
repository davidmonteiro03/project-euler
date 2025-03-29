/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:33:43 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/28 23:44:47 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static void	nums_fill(t_solution *solution, char *filename)
{
	FILE	*f;
	char	format[BUFSIZ];
	size_t	i;
	int		ret;

	if (solution == NULL || filename == NULL || g_exit_status != EX_OK)
		return (g_exit_status = EX__BASE, (void)0);
	f = fopen(filename, "r");
	if (f == NULL)
		return (g_exit_status = EX__BASE, (void)0);
	bzero(format, sizeof(format));
	sprintf(format, "%%%zus", solution->size);
	i = 0;
	while (i < solution->length)
	{
		ret = fscanf(f, format, solution->nums[i]);
		if (ret != 1)
			return (fclose(f), g_exit_status = EX__BASE, (void)0);
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
		fprintf(stderr, "usage: %s <filename>\n", solution->argv[0]);
		g_exit_status = EX_USAGE;
		return ;
	}
	nums_fill(solution, solution->argv[1]);
}
