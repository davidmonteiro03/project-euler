/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:33:22 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/01 14:08:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static char	*read_file(char *filename)
{
	char	*result;
	FILE	*f;
	size_t	size;

	if (filename == NULL)
		return (g_exit_status = EX__BASE, NULL);
	f = fopen(filename, "r");
	if (f == NULL)
		return (g_exit_status = EX__BASE, NULL);
	fseek(f, 0, SEEK_END);
	size = ftell(f);
	rewind(f);
	result = (char *)malloc(size + 1);
	if (result == NULL)
		return (fclose(f), NULL);
	if (fread(result, 1, size, f) != size)
		return (free(result), fclose(f), NULL);
	result[size] = '\0';
	return (fclose(f), result);
}

static size_t	count_names(char *str)
{
	size_t	count;
	size_t	i;
	size_t	j;

	if (str == NULL)
		return (0);
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\"')
		{
			j = ++i;
			while (str[i] != '\0' && str[i] != '\"')
				i++;
			if (str[i] == '\0')
				break ;
			if (i++ > j)
				count++;
			continue ;
		}
		while (str[i] != '\0' && str[i] != '\"')
			i++;
	}
	return (count);
}

static void	names_fill(t_solution *solution, char *str, size_t i, size_t k)
{
	size_t	j;

	if (solution == NULL || str == NULL)
		return ;
	solution->names = (char **)malloc(sizeof(char *) * (solution->length + 1));
	bzero(solution->names, sizeof(char *) * (solution->length + 1));
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\"')
		{
			j = ++i;
			while (str[i] != '\0' && str[i] != '\"')
				i++;
			if (str[i] == '\0')
				break ;
			if (i > j)
				solution->names[k++] = strndup(&str[j], i - j);
			i++;
			continue ;
		}
		while (str[i] != '\0' && str[i] != '\"')
			i++;
	}
}

void	solution_fill(t_solution *solution)
{
	char	*content;

	if (solution == NULL || g_exit_status != EX_OK)
		return ;
	if (solution->argc != 2)
	{
		fprintf(stderr, "usage: %s <filename>\n", solution->argv[0]);
		g_exit_status = EX_USAGE;
		return ;
	}
	content = read_file(solution->argv[1]);
	if (content == NULL)
		return ;
	solution->length = count_names(content);
	names_fill(solution, content, 0, 0);
	free(content);
}
