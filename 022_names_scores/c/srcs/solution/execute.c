/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:26:58 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/01 13:57:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static void	sort_names(char **names)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	if (names == NULL || *names == NULL)
		return ;
	i = 0;
	while (names[i] != NULL && names[i + 1] != NULL)
	{
		j = i + 1;
		while (names[j] != NULL)
		{
			if (strcmp(names[i], names[j]) > 0)
			{
				tmp = names[i];
				names[i] = names[j];
				names[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static long long int	get_letter_code(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 65 + 1);
	if (c >= 'a' && c <= 'z')
		return (c - 97 + 1);
	return (0);
}

static long long int	get_name_score(char *name, long long int pos)
{
	long long int	result;
	size_t			i;

	if (name == NULL || pos < 0)
		return (0);
	result = 0;
	i = 0;
	while (name[i] != '\0')
		result += get_letter_code(name[i++]);
	result *= pos + 1;
	return (result);
}

static void	solve(char **names, char *filename)
{
	long long int	solution;
	size_t			i;

	solution = 0;
	if (names == NULL || *names == NULL || filename == NULL)
		return ;
	sort_names(names);
	i = 0;
	while (names[i] != NULL)
	{
		solution += get_name_score(names[i], i);
		i++;
	}
	fprintf(stdout, "Solution for %s: %lld\n", filename, solution);
}

void	solution_execute(t_solution *solution)
{
	size_t	i;

	if (solution == NULL || solution->names == NULL || g_exit_status != EX_OK)
		return ;
	solve(solution->names, solution->argv[1]);
	i = 0;
	while (i < solution->length)
	{
		if (solution->names[i] != NULL)
			free(solution->names[i]);
		i++;
	}
	free(solution->names);
}
