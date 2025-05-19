/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/05/19 15:53:30 by dcaetano         ###   ########.fr       */
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

std::size_t Solution::__numLen(const long long int &n)
{
	std::stringstream ss;
	ss << n;
	return ss.str().size();
}

bool Solution::__isTruncablePrime(const long long int &n)
{
	if (n < 10 || Solution::__isPrime(n) == false)
		return false;
	std::size_t nLen = Solution::__numLen(n);
	for (std::size_t i = 0; i < nLen; i++)
	{
		long long int nPow = static_cast<long long int>(std::pow(10., static_cast<double>(nLen - i)));
		if (Solution::__isPrime(n % nPow) == false)
			return false;
	}
	for (std::size_t i = 0; i < nLen; i++)
	{
		long long int nPow = static_cast<long long int>(std::pow(10., static_cast<double>(i)));
		if (Solution::__isPrime(n / nPow) == false)
			return false;
	}
	return true;
}

void Solution::__solve(const long long int &n)
{
	if (n < 0)
		return;
	long long int solution = 0;
	std::size_t count = 0;
	for (long long int i = 1; count < static_cast<std::size_t>(n); i++)
	{
		if (Solution::__isTruncablePrime(i) == true)
		{
			count++;
			solution += i;
		}
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
