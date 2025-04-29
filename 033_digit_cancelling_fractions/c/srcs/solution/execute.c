/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/29 20:06:55 by dcaetano         ###   ########.fr       */
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
	long long int	solution;
	long long int	f[2];
	long long int	*ac;
	mpq_t			q[2];

	mpq_init(q[1]);
	mpq_set_ui(q[1], 1, 1);
	f[0] = 0;
	while (++f[0] < (long long int)pow(10, n))
	{
		f[1] = f[0];
		while (++f[1] < (long long int)pow(10, n))
		{
			ac = compute_ac(f[0], f[1]);
			if (ac == NULL)
				continue ;
			if ((f[0] != ac[0] || f[1] != ac[1]) && ((double)f[0]
					/ (double)f[1]) == ((double)ac[0] / (double)ac[1]))
			{
				mpq_init(q[0]);
				mpq_set_ui(q[0], f[0], f[1]);
				mpq_canonicalize(q[0]);
				mpq_mul(q[1], q[1], q[0]);
				mpq_clear(q[0]);
			}
			free(ac);
		}
	}
	solution = mpz_get_ui(mpq_denref(q[1]));
	fprintf(stdout, "Solution for %lld: %lld\n", n, solution);
	mpq_clear(q[1]);
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
