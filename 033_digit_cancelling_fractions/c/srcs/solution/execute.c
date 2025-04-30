/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/30 09:30:12 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static char	*remove_char(char *str, const char c)
{
	char	*result;
	size_t	is[2];
	bool	removed;

	if (str == NULL)
		return (NULL);
	if (c == '\0')
		return (str);
	if (strchr(str, c) == NULL)
		return (str);
	result = (char *)malloc(sizeof(char) * strlen(str));
	if (result == NULL)
		return (NULL);
	bzero(result, sizeof(char) * strlen(str));
	removed = false;
	is[1] = 0;
	is[0] = -1;
	while (++is[0] < strlen(str))
	{
		if (removed == false && str[is[0]] == c)
			removed = true;
		else
			result[is[1]++] = str[is[0]];
	}
	return (free(str), result);
}

static void	remove_common(char **a, char **b)
{
	size_t	i;
	char	c;

	i = 0;
	while ((*a)[i] != '\0')
	{
		if (strchr(*b, (*a)[i]) != NULL)
		{
			c = (*a)[i];
			*a = remove_char(*a, c);
			*b = remove_char(*b, c);
			i = 0;
		}
		else
			i++;
	}
}

static long long int	*compute_ac(long long int n, long long int d)
{
	long long int	*result;
	const size_t	size = sizeof(long long int) * 2;
	char			buf[2][BUFSIZ];
	char			*tmp[2];
	const char		*fmt = "%lld";

	result = (long long int *)malloc(size);
	if (result == NULL)
		return (NULL);
	if (n < 10 || d < 10 || (n % 10 == 0 && d % 10 == 0))
		return (free(result), NULL);
	bzero(result, size);
	bzero(buf, sizeof(buf));
	snprintf(buf[0], sizeof(buf[0]) / sizeof(char), fmt, n);
	snprintf(buf[1], sizeof(buf[1]) / sizeof(char), fmt, d);
	tmp[0] = strdup(buf[0]);
	if (tmp[0] == NULL)
		return (free(result), NULL);
	tmp[1] = strdup(buf[1]);
	if (tmp[1] == NULL)
		return (free(tmp[1]), free(result), NULL);
	remove_common(&tmp[0], &tmp[1]);
	sscanf(tmp[0], fmt, &result[0]);
	sscanf(tmp[1], fmt, &result[1]);
	return (free(tmp[1]), free(tmp[0]), result);
}

static void	solve(long long int n)
{
	mpz_t	solution;
	mpq_t	product;
	t_help	help;

	mpz_init_set_ui(solution, 0);
	mpq_init(product);
	mpq_set_ui(product, 1, 1);
	help.f[0] = 0;
	while (++help.f[0] < (long long int)pow(10, n))
	{
		help.f[1] = help.f[0];
		while (++help.f[1] < (long long int)pow(10, n))
		{
			help.ac = compute_ac(help.f[0], help.f[1]);
			if (help.ac == NULL)
				continue ;
			help_compute(product, &help);
			free(help.ac);
		}
	}
	mpq_canonicalize(product);
	mpz_set(solution, mpq_denref(product));
	gmp_fprintf(stdout, "Solution for %lld: %Zd\n", n, solution);
	mpq_clear(product);
	mpz_clear(solution);
}

void	solution_execute(t_solution *solution)
{
	long long int	n;
	int				ret;

	if (solution == NULL)
		return ;
	if (solution->argc != 2)
	{
		fprintf(stderr, "usage: %s <n>\n", solution->argv[0]);
		g_exit_status = EX_USAGE;
		return ;
	}
	n = 0;
	ret = sscanf(solution->argv[1], "%lld", &n);
	if (ret == -1)
	{
		fprintf(stderr, "%s: error: '%s' is not an integer.\n",
			solution->argv[0], solution->argv[1]);
		g_exit_status = EX_DATAERR;
		return ;
	}
	solve(n);
}
