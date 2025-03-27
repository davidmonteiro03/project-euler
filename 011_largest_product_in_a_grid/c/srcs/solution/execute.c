/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 18:43:27 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static long long int	compute_max_horiz_prod(t_solution *solution, size_t len)
{
	size_t			i;
	size_t			j;
	size_t			k;
	long long int	prod;
	long long int	result;

	if (solution == NULL || len == 0)
		return (0);
	result = 0;
	i = -1;
	while (++i < solution->m - len + 1)
	{
		j = -1;
		while (++j < solution->n - len + 1)
		{
			prod = 1;
			k = -1;
			while (++k < len)
				prod *= solution->grid[i][j + k];
			if (prod > result)
				result = prod;
		}
	}
	return (result);
}

static long long int	compute_max_vert_prod(t_solution *solution, size_t len)
{
	size_t			i;
	size_t			j;
	size_t			k;
	long long int	prod;
	long long int	result;

	if (solution == NULL || len == 0)
		return (0);
	result = 0;
	i = -1;
	while (++i < solution->m - len + 1)
	{
		j = -1;
		while (++j < solution->n - len + 1)
		{
			prod = 1;
			k = -1;
			while (++k < len)
				prod *= solution->grid[i + k][j];
			if (prod > result)
				result = prod;
		}
	}
	return (result);
}

static long long int	compute_max_diag_prod(t_solution *solution, size_t len)
{
	size_t			i;
	size_t			j;
	size_t			k;
	long long int	prod;
	long long int	result;

	if (solution == NULL || len == 0)
		return (0);
	result = 0;
	i = -1;
	while (++i < solution->m - len + 1)
	{
		j = -1;
		while (++j < solution->n - len + 1)
		{
			prod = 1;
			k = -1;
			while (++k < len)
				prod *= solution->grid[i + k][j + k];
			if (prod > result)
				result = prod;
		}
	}
	return (result);
}

static long long int	compute_max_rdiag_prod(t_solution *solution, size_t len)
{
	size_t			i;
	size_t			j;
	size_t			k;
	long long int	prod;
	long long int	result;

	if (solution == NULL || len == 0)
		return (0);
	result = 0;
	i = -1;
	while (++i < solution->m - len + 1)
	{
		j = -1;
		while (++j < solution->n - len + 1)
		{
			prod = 1;
			k = -1;
			while (++k < len)
				prod *= solution->grid[i + k][j + len - k - 1];
			if (prod > result)
				result = prod;
		}
	}
	return (result);
}

void	solution_execute(t_solution *solution)
{
	long long int	result;
	long long int	max_horiz_prod;
	long long int	max_vert_prod;
	long long int	max_diag_prod;
	long long int	max_rdiag_prod;

	if (solution == NULL)
		return ;
	result = 0;
	max_horiz_prod = compute_max_horiz_prod(solution, 4);
	max_vert_prod = compute_max_vert_prod(solution, 4);
	max_diag_prod = compute_max_diag_prod(solution, 4);
	max_rdiag_prod = compute_max_rdiag_prod(solution, 4);
	if (max_horiz_prod > result)
		result = max_horiz_prod;
	if (max_vert_prod > result)
		result = max_vert_prod;
	if (max_diag_prod > result)
		result = max_diag_prod;
	if (max_rdiag_prod > result)
		result = max_rdiag_prod;
	fprintf(stdout, "Solution for \"%s\": %lld\n", solution->argv[1], result);
}
