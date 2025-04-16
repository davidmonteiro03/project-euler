/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/16 11:35:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static char	*strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	len;
	size_t	size;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = strlen(s1) + strlen(s2);
	size = sizeof(char) * (len + 1);
	joined = (char *)malloc(size);
	if (joined == NULL)
		return (NULL);
	bzero(joined, size);
	strcpy(joined, s1);
	strcat(joined, s2);
	free(s1);
	free(s2);
	return (joined);
}

static char	*decimal_period(long long int remainder, long long int divisor)
{
	long long int	*storage;
	long long int	i;
	char			*decimal;
	char			buf[BUFSIZ];
	char			*result;

	storage = (long long int *)malloc(sizeof(long long int) * divisor);
	if (storage == NULL)
		return (NULL);
	memset(storage, -1, sizeof(long long int) * divisor);
	decimal = strdup("");
	i = 0;
	while (remainder != 0 && storage[remainder] == -1)
	{
		storage[remainder] = i++;
		remainder *= 10;
		bzero(buf, sizeof(buf));
		sprintf(buf, "%lld", remainder / divisor);
		decimal = strjoin(decimal, strdup(buf));
		remainder %= divisor;
	}
	result = strdup(&decimal[storage[remainder] * (remainder != 0)]);
	return (free(storage), free(decimal), result);
}

static size_t	reciprocal_cycle(long long int dividend, long long int divisor)
{
	long long int	remainder;
	char			*period;
	size_t			result;

	if (divisor == 0)
		return (0);
	remainder = dividend % divisor;
	if (remainder != 0)
	{
		period = decimal_period(remainder, divisor);
		if (period == NULL)
			return (0);
		result = strlen(period);
		free(period);
		return (result);
	}
	return (0);
}

static void	solve(long long int n)
{
	long long int	solution;
	long long int	i;
	size_t			max_len;
	size_t			tmp_len;

	solution = 0;
	i = 1;
	max_len = 0;
	while (i < n)
	{
		tmp_len = reciprocal_cycle(1, i);
		if (tmp_len > max_len)
		{
			solution = i;
			max_len = tmp_len;
		}
		i++;
	}
	fprintf(stdout, "Solution for %lld: %lld\n", n, solution);
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
