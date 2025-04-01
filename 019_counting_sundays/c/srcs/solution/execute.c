/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/01 09:21:58 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static long long int	get_month_days(long long int m, long long int y)
{
	if (y < 0)
		return (0);
	if (m == 2)
		return (28 + (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)));
	return (30 + ((m % 2 == 1 && m <= 7) || (m % 2 == 0 && m > 7)));
}

static long long int	count_first_sundays_from_to(struct tm *sd,
		struct tm *ed)
{
	long long int	count;
	struct tm		i;
	struct tm		limit;

	count = 0;
	if (sd == NULL || ed == NULL)
		return (0);
	bzero(&i, sizeof(i));
	bzero(&limit, sizeof(limit));
	memcpy(&i, sd, sizeof(i));
	memcpy(&limit, ed, sizeof(limit));
	mktime(&i);
	while (i.tm_year < limit.tm_year || (i.tm_year == limit.tm_year
			&& i.tm_yday <= limit.tm_yday))
	{
		count += (i.tm_mday++ == 1 && i.tm_wday == 0);
		mktime(&i);
	}
	return (count);
}

static void	solve(struct tm *sd, struct tm *ed)
{
	long long int	solution;
	char			sd_str[BUFSIZ];
	char			ed_str[BUFSIZ];

	solution = 0;
	if (sd == NULL || ed == NULL)
		return ;
	if (sd->tm_mday > get_month_days(sd->tm_mon + 1, sd->tm_year + 1900)
		|| ed->tm_mday > get_month_days(ed->tm_mon + 1, ed->tm_year + 1900))
		return ;
	bzero(sd_str, sizeof(sd_str));
	bzero(ed_str, sizeof(ed_str));
	strftime(sd_str, sizeof(sd_str), "%d/%m/%Y", sd);
	strftime(ed_str, sizeof(ed_str), "%d/%m/%Y", ed);
	solution = count_first_sundays_from_to(sd, ed);
	fprintf(stdout, "Solution for [%s - %s]: %lld\n", sd_str, ed_str, solution);
}

void	solution_execute(t_solution *solution)
{
	struct tm	sd;
	struct tm	ed;
	char		*c[2];

	if (solution == NULL)
		return ;
	if (solution->argc != 3)
	{
		fprintf(stderr, "usage: %s <start_date> <end_date>\n",
			solution->argv[0]);
		g_exit_status = EX_USAGE;
		return ;
	}
	bzero(&sd, sizeof(sd));
	bzero(&ed, sizeof(ed));
	c[0] = strptime(solution->argv[1], "%d %b %Y", &sd);
	c[1] = strptime(solution->argv[2], "%d %b %Y", &ed);
	if (c[0] == NULL || c[1] == NULL || *c[0] != '\0' || *c[1] != '\0')
	{
		fprintf(stderr, "%s: error: '%s' and '%s' are not in a valid \
date format.\n", solution->argv[0], solution->argv[1], solution->argv[2]);
		g_exit_status = EX_DATAERR;
		return ;
	}
	solve(&sd, &ed);
}
