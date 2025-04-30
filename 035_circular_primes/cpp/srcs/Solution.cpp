/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/30 14:54:01 by dcaetano         ###   ########.fr       */
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

bool Solution::__isPrime(const long long int &n)
{
	if (n <= 1)
		return false;
	for (long long int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

std::string Solution::__rotateStr(const std::string &str)
{
	if (str.empty() || str.size() < 2)
		return str;
	std::string result(str);
	char first = result.front();
	result.erase(result.begin());
	result.push_back(first);
	return result;
}

bool Solution::__checkCircularPrime(const long long int &n)
{
	std::stringstream nSs;
	nSs << n;
	std::string nStr = nSs.str();
	for (std::size_t k = 0; k < nStr.size(); k++)
	{
		long long int tmpN = 0;
		std::stringstream tmpNSs(nStr);
		tmpNSs >> tmpN;
		if (Solution::__isPrime(tmpN) == false)
			return false;
		nStr = Solution::__rotateStr(nStr);
	}
	return true;
}

void Solution::__solve(const long long int &limit)
{
	long long int solution = 0;
	for (int i = 1; i < limit; i++)
		solution += Solution::__checkCircularPrime(i);
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
