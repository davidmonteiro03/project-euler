/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/01 11:18:31 by dcaetano         ###   ########.fr       */
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

long long int Solution::__computeD(const long long int &n)
{
	long long int result = 0;
	for (long long int i = 1; i < n; i++)
		if (n % i == 0)
			result += i;
	return result;
}

void Solution::__solve(const long long int &n)
{
	long long int solution = 0;
	for (long long int i = 1; i < n; i++)
	{
		long long int a = Solution::__computeD(i);
		long long int b = Solution::__computeD(a);
		if (a != b && i == b)
			solution += i;
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
