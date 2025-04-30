/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/30 13:08:47 by dcaetano         ###   ########.fr       */
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

void Solution::__solve(const long long int &limit)
{
	boost::multiprecision::cpp_int solution = 0;
	for (long long int i = 10; i <= limit && i <= 100000; i++)
	{
		std::stringstream iSs;
		iSs << i;
		std::string iStr = iSs.str();
		boost::multiprecision::cpp_int iCopy = i;
		boost::multiprecision::cpp_int fSum = 0;
		for (std::size_t k = 0; k < iStr.size(); k++)
		{
			boost::multiprecision::cpp_int fac = 1;
			for (long long int j = static_cast<long long int>(iStr[k] - '0'); j > 1; j--)
				fac *= j;
			fSum += fac;
		}
		if (iCopy == fSum)
			solution += iCopy;
	}
	std::cout << "Solution for " << limit << ": " << solution << std::endl;
}

void Solution::execute(void) const
{
	if (this->__argc != 2)
	{
		std::cerr << "usage: " << this->__argv[0] << " <limit>" << std::endl;
		gExitStatus = EX_USAGE;
		return;
	}
	long long int limit = 0;
	std::stringstream tmp(this->__argv[1]);
	if (!(tmp >> limit))
	{
		std::cerr << this->__argv[0] << ": error: '" << this->__argv[1] << "' is not an integer." << std::endl;
		gExitStatus = EX_DATAERR;
		return;
	}
	Solution::__solve(limit);
}
