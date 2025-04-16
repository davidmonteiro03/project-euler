/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/16 11:38:00 by dcaetano         ###   ########.fr       */
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

std::string Solution::__decimalPeriod(const long long int &remainder,
									  const long long int &divisor)
{
	long long int tmpRemainder = remainder;
	std::vector<long long int> storage(divisor);
	for (std::vector<long long int>::iterator it = storage.begin(); it != storage.end(); it++)
		*it = -1;
	std::string decimal = "";
	for (long long int i = 0; tmpRemainder != 0 && storage[tmpRemainder] == -1; i++)
	{
		storage[tmpRemainder] = i;
		tmpRemainder *= 10;
		std::stringstream ss;
		ss << tmpRemainder / divisor;
		decimal += ss.str();
		tmpRemainder %= divisor;
	}
	if (tmpRemainder == 0)
		return decimal;
	return decimal.substr(storage[tmpRemainder]);
}

std::size_t Solution::__reciprocalCycle(const long long int &dividend,
										const long long int &divisor)
{
	if (divisor == 0)
		return 0;
	long long int remainder = dividend % divisor;
	if (remainder != 0)
	{
		std::string period = Solution::__decimalPeriod(remainder, divisor);
		if (period.empty())
			return 0;
		return period.size();
	}
	return 0;
}

void Solution::__solve(const long long int &n)
{
	long long int solution = 0;
	std::size_t maxLen = 0;
	for (long long int i = 1; i < n; i++)
	{
		std::size_t tmpLen = Solution::__reciprocalCycle(1, i);
		if (tmpLen > maxLen)
		{
			solution = i;
			maxLen = tmpLen;
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
