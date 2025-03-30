/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/30 21:01:42 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static void	show_number(size_t *solution, long long int n)
{
	const long long int	d[3] = {n / 100, (n % 100) / 10, n % 10};
	const char			*main_str[10] = {"zero", "one", "two", "three", "four", \
					"five", "six", "seven", "eight", "nine"};
	const char			*teen_str[10] = {"ten", "eleven", "twelve", "thirteen", \
					"fourteen", "fifteen", "sixteen", "seventeen", "eighteen", \
					"nineteen"};
	const char			*ty_str[10] = {NULL, "ten", "twenty", "thirty", "forty", \
					"fifty", "sixty", "seventy", "eighty", "ninety"};
	char				tmp[BUFSIZ];

	bzero(tmp, sizeof(tmp));
	if (d[0] > 0)
		*solution += sprintf(tmp, "%shundred", main_str[d[0]]);
	if (d[0] > 0 && d[1] + d[2] > 0)
		*solution += sprintf(tmp, "and");
	if (d[1] > 0)
	{
		if (d[1] == 1)
			*solution += sprintf(tmp, "%s", teen_str[d[2]]);
		else
			*solution += sprintf(tmp, "%s", ty_str[d[1]]);
	}
	if (d[2] > 0 && d[1] != 1)
		*solution += sprintf(tmp, "%s", main_str[d[2]]);
}

static void	analyse_number(size_t *solution, long long int n)
{
	if (n > 999)
	{
		analyse_number(solution, n / 1000);
		analyse_number(solution, n % 1000);
		return ;
	}
	else
		show_number(solution, n);
}

static void	solve(long long int start, long long int end)
{
	size_t			solution;
	long long int	i;
	char			tmp[BUFSIZ];

	solution = 0;
	i = start;
	while (i <= end)
	{
		bzero(tmp, sizeof(tmp));
		if (i == 0)
			solution += sprintf(tmp, "zero");
		else
			analyse_number(&solution, i);
		if (i >= 1000)
			solution += sprintf(tmp, "thousand");
		i++;
	}
	fprintf(stdout, "Solution for [%lld, %lld]: %zu\n", start, end, solution);
}

void	solution_execute(t_solution *solution)
{
	long long int	start;
	long long int	end;
	int				ret_start;
	int				ret_end;

	if (solution == NULL)
		return ;
	if (solution->argc != 3)
	{
		fprintf(stderr, "usage: %s <start> <end>\n", solution->argv[0]);
		g_exit_status = EX_USAGE;
		return ;
	}
	start = 0;
	end = 0;
	ret_start = sscanf(solution->argv[1], "%lld", &start);
	ret_end = sscanf(solution->argv[2], "%lld", &end);
	if (ret_start == -1 || ret_end == -1)
	{
		fprintf(stderr, "%s: error: '%s' and '%s' are not both integers.\n",
			solution->argv[0], solution->argv[1], solution->argv[2]);
		g_exit_status = EX_DATAERR;
		return ;
	}
	solve(start, end);
}
