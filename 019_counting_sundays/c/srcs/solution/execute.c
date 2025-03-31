/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:13:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/31 18:30:44 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static long long int	get_month_days(long long int m, long long int y)
{
	if (m == 2)
		return (28 + (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)));
	return (30 + ((m % 2 != 0 && m < 8) || (m >= 8 && m % 2 == 0)));
}

static bool	check_date(long long int *dt)
{
	long long int	d;
	long long int	m;
	long long int	y;

	d = dt[0];
	m = dt[1];
	y = dt[2];
	if (y < 0)
		return (false);
	return (m >= 1 && m <= 12 && d >= 1 && d <= get_month_days(m, y));
}

static long long int	count_first_sundays(long long int *s_dt,
		long long int *e_dt)
{
	struct tm	tmp;
	int			count;
	const char	*week_days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", \
			"Friday", "Saturday", "Sunday"};

	(void)e_dt;
	bzero(&tmp, sizeof(tmp));
	tmp.tm_mday = s_dt[0];
	tmp.tm_mon = s_dt[1] - 1;
	tmp.tm_year = s_dt[2] - 1900;
	mktime(&tmp);
	fprintf(stdout, "tmp: %02d/%02d/%04d (%s)\n", tmp.tm_mday, tmp.tm_mon + 1,
		tmp.tm_year + 1900, week_days[tmp.tm_wday - 1]);
	count = 0;
	return (count);
}

static void	solve(long long int *s_dt, long long int *e_dt)
{
	long long int	solution;
	char			s_dt_buf[BUFSIZ];
	char			e_dt_buf[BUFSIZ];

	solution = 0;
	bzero(s_dt_buf, sizeof(s_dt_buf));
	bzero(e_dt_buf, sizeof(e_dt_buf));
	if (check_date(s_dt) == false || check_date(e_dt) == false)
		return (g_exit_status = EX__BASE, (void)0);
	solution = count_first_sundays(s_dt, e_dt);
	sprintf(s_dt_buf, "%02lld/%02lld/%04lld", s_dt[0], s_dt[1], s_dt[2]);
	sprintf(e_dt_buf, "%02lld/%02lld/%04lld", e_dt[0], e_dt[1], e_dt[2]);
	fprintf(stdout, "Solution for [%s - %s]: %lld\n", s_dt_buf, e_dt_buf,
		solution);
}

void	solution_execute(t_solution *solution)
{
	long long int	s_dt[3];
	long long int	e_dt[3];

	if (solution == NULL)
		return ;
	if (solution->argc != 3)
	{
		fprintf(stderr, "usage: %s <start_date> <end_date>\n",
			solution->argv[0]);
		g_exit_status = EX_USAGE;
		return ;
	}
	bzero(s_dt, sizeof(s_dt));
	bzero(e_dt, sizeof(e_dt));
	if (sscanf(solution->argv[1], "%lld - %lld - %lld", &s_dt[0], &s_dt[1],
			&s_dt[2]) == -1 || sscanf(solution->argv[2], "%lld - %lld - %lld",
			&e_dt[0], &e_dt[1], &e_dt[2]) == -1)
	{
		fprintf(stderr,
			"%s: error: '%s' and '%s' are not both in a valid date format.\n",
			solution->argv[0], solution->argv[1], solution->argv[2]);
		g_exit_status = EX_DATAERR;
		return ;
	}
	solve(s_dt, e_dt);
}
