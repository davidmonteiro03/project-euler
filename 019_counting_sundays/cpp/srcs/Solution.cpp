/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/01 09:41:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solve_cpp.hpp"

Solution::Solution(int argc, char **argv) : __argc(argc),
											__argv(argv) {}

Solution::Solution(const Solution &copy) : __argc(copy.__argc),
										   __argv(copy.__argv) {}

Solution &Solution::operator=(const Solution &other)
{
	if (this != &other)
	{
		this->__argc = other.__argc;
		this->__argv = other.__argv;
	}
	return *this;
}

Solution::~Solution() {}

long long int Solution::__getMonthDays(const long long int &m,
									   const long long int &y)
{
	if (y < 0)
		return 0;
	return m == 2 ? 28 + (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) : 30 + ((m % 2 == 1 && m <= 7) || (m % 2 == 0 && m > 7));
}

long long int Solution::__countFirstSundaysFromTo(const struct tm &sd,
												  const struct tm &ed)
{
	long long int count = 0;
	struct tm i, limit;
	bzero(&i, sizeof(i));
	bzero(&limit, sizeof(limit));
	std::memcpy(&i, &sd, sizeof(i));
	std::memcpy(&limit, &ed, sizeof(limit));
	std::mktime(&i);
	while (i.tm_year < limit.tm_year || (i.tm_year == limit.tm_year && i.tm_yday <= limit.tm_yday))
	{
		count += (i.tm_mday++ == 1 && i.tm_wday == 0);
		mktime(&i);
	}
	return count;
}

void Solution::__solve(const struct tm &sd,
					   const struct tm &ed)
{
	long long int solution = 0;
	if (sd.tm_mday > Solution::__getMonthDays(sd.tm_mon + 1, sd.tm_year + 1900) || ed.tm_mday > Solution::__getMonthDays(ed.tm_mon + 1, ed.tm_year + 1900))
		return;
	char sdStr[BUFSIZ], edStr[BUFSIZ];
	bzero(sdStr, sizeof(sdStr));
	bzero(edStr, sizeof(edStr));
	std::strftime(sdStr, sizeof(sdStr), "%d/%m/%Y", &sd);
	std::strftime(edStr, sizeof(edStr), "%d/%m/%Y", &ed);
	solution = Solution::__countFirstSundaysFromTo(sd, ed);
	std::cout << "Solution for [" << sdStr << " - " << edStr << "]: " << solution << std::endl;
}

void Solution::execute(void) const
{
	if (this->__argc != 3)
	{
		std::cerr << "usage: " << this->__argv[0] << " <start_date> <end_date>" << std::endl;
		gExitStatus = EX_USAGE;
		return;
	}
	struct tm sd, ed;
	bzero(&sd, sizeof(sd));
	bzero(&ed, sizeof(ed));
	char *csd = strptime(this->__argv[1], "%d %b %Y", &sd);
	char *ced = strptime(this->__argv[2], "%d %b %Y", &ed);
	if (csd == NULL || ced == NULL || *csd != '\0' || *ced != '\0')
	{
		std::cerr << this->__argv[0] << ": error: '" << this->__argv[1] << "' and '" << this->__argv[2] << "' are not in a valid date format." << std::endl;
		gExitStatus = EX_DATAERR;
		return;
	}
	Solution::__solve(sd, ed);
}
