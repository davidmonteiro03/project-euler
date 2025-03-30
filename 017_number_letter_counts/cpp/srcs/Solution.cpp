/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/30 21:09:08 by dcaetano         ###   ########.fr       */
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

void Solution::__showNumber(size_t &solution,
							const long long int &n)
{
	long long int d[3] = {n / 100, (n % 100) / 10, n % 10};
	const std::string mainStr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	const std::string teenStr[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	const std::string tyStr[10] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	std::stringstream tmp;
	if (d[0] > 0)
		tmp << mainStr[d[0]] << "hundred";
	if (d[0] > 0 && d[1] + d[2] > 0)
		tmp << "and";
	if (d[1] > 0)
	{
		if (d[1] == 1)
			tmp << teenStr[d[2]];
		else
			tmp << tyStr[d[1]];
	}
	if (d[2] > 0 && d[1] != 1)
		tmp << mainStr[d[2]];
	solution += tmp.str().size();
}

void Solution::__analyseNumber(size_t &solution, const long long int &n)
{
	if (n > 999)
	{
		Solution::__analyseNumber(solution, n / 1000);
		Solution::__analyseNumber(solution, n % 1000);
		return;
	}
	else
		Solution::__showNumber(solution, n);
}

void Solution::__solve(const long long int &start,
					   const long long int &end)
{
	size_t solution = 0;
	for (long long int i = start; i <= end; i++)
	{
		std::stringstream tmp;
		if (i == 0)
		{
			tmp << "zero";
			solution += tmp.str().size();
		}
		else
			Solution::__analyseNumber(solution, i);
		if (i >= 1000)
		{
			tmp << "thousand";
			solution += tmp.str().size();
		}
	}
	std::cout << "Solution for [" << start << ", " << end << "]: " << solution << std::endl;
}

void Solution::execute(void) const
{
	if (this->__argc != 3)
	{
		std::cerr << "usage: " << this->__argv[0] << " <start> <end>" << std::endl;
		gExitStatus = EX_USAGE;
		return;
	}
	long long int start = 0;
	long long int end = 0;
	std::stringstream tmpStartSs(this->__argv[1]);
	std::stringstream tmpEndSs(this->__argv[2]);
	if (!(tmpStartSs >> start) || !(tmpEndSs >> end))
	{
		std::cerr << this->__argv[0] << ": error: '" << this->__argv[1] << "' and '" << this->__argv[2] << "' are not both integers." << std::endl;
		gExitStatus = EX_DATAERR;
		return;
	}
	Solution::__solve(start, end);
}
