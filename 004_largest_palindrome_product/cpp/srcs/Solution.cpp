/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/30 15:01:06 by dcaetano         ###   ########.fr       */
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

long long int Solution::__getLimit(const long long int &n)
{
	long long int limit = 1, tmp_n = n;
	while (tmp_n-- > 1)
		limit *= 10;
	return limit;
}

long long int Solution::__updateSolution(const long long int &solution,
										 const long long int &i,
										 const long long int &j)
{
	std::stringstream buf;
	buf << i * j;
	std::string bufStr = buf.str();
	size_t len = bufStr.size();
	bool palindrome = true;
	for (size_t k = 0; k < len / 2; k++)
	{
		if (bufStr[k] != bufStr[len - k - 1])
		{
			palindrome = false;
			break;
		}
	}
	if (palindrome == true && i * j > solution)
		return i * j;
	return solution;
}

void Solution::__solve(const long long int &n)
{
	long long int solution = 0, i = Solution::__getLimit(n);
	long long int limit = i * 10;
	while (i < limit)
	{
		for (long long int j = ++i; j < limit; j++)
			solution = Solution::__updateSolution(solution, i, j);
	}
	std::cout << "Solution for " << n << ": " << solution << std::endl;
}

void Solution::execute(void) const
{
	if (this->__argc != 2)
	{
		std::cerr << "usage: " << this->__argv[0] << " <n>" << std::endl;
		gExitStatus = EX_USAGE;
		return;
	}
	long long int n = 0;
	std::stringstream tmp(this->__argv[1]);
	if (!(tmp >> n))
	{
		std::cerr << this->__argv[0] << ": error: '" << this->__argv[1] << "' is not an integer." << std::endl;
		gExitStatus = EX_DATAERR;
		return;
	}
	Solution::__solve(n);
}
