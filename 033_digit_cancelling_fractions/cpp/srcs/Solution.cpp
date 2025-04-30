/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/30 14:48:16 by dcaetano         ###   ########.fr       */
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

void Solution::__removeCommon(std::string &a,
							  std::string &b)
{
	for (std::size_t i = 0; i < a.size();)
	{
		if (std::strchr(b.c_str(), a[i]) != NULL)
		{
			std::size_t findAPos = a.find(a[i]), findBPos = b.find(a[i]);
			a.erase(a.begin() + findAPos);
			b.erase(b.begin() + findBPos);
			i = 0;
		}
		else
			i++;
	}
}

std::pair<long long int, long long int> Solution::__computeAC(const long long int &numerator,
															  const long long int &denominator)
{
	std::pair<long long int, long long int> result;
	result.first = 0;
	result.second = 0;
	std::stringstream numeratorBeforeSs, denominatorBeforeSs;
	numeratorBeforeSs << numerator;
	denominatorBeforeSs << denominator;
	std::string numeratorStr = numeratorBeforeSs.str(), denominatorStr = denominatorBeforeSs.str();
	Solution::__removeCommon(numeratorStr, denominatorStr);
	std::stringstream numeratorAfterSs(numeratorStr), denominatorAfterSs(denominatorStr);
	numeratorAfterSs >> result.first;
	denominatorAfterSs >> result.second;
	return result;
}

void Solution::__solve(const long long int &n)
{
	boost::multiprecision::cpp_int solution = 0;
	boost::multiprecision::cpp_rational product(1, 1);
	for (long long int numerator = 1; numerator < std::pow(10, n); numerator++)
	{
		for (long long int denominator = numerator + 1; denominator < std::pow(10, n); denominator++)
		{
			if (numerator < 10 || denominator < 10)
				continue;
			if (numerator % 10 == 0 && denominator % 10 == 0)
				continue;
			std::pair<long long int, long long int> ac = Solution::__computeAC(numerator, denominator);
			if (numerator == ac.first && denominator == ac.second)
				continue;
			if (denominator == 0 || ac.second == 0)
				continue;
			boost::multiprecision::cpp_rational q0(numerator, denominator), q1(ac.first, ac.second);
			if (q0 != q1)
				continue ;
			product *= q1;
		}
	}
	solution = boost::multiprecision::denominator(product);
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
