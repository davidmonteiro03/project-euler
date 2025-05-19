/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/05/19 15:15:20 by dcaetano         ###   ########.fr       */
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

bool Solution::__isPalindrome(const std::string &str)
{
	std::size_t len = str.size();
	for (std::size_t i = 0; i < len / 2; i++)
		if (str[i] != str[len - i - 1])
			return false;
	return true;
}

std::string Solution::__ztosBase(const boost::multiprecision::cpp_int &z,
								 const std::string &strBase)
{
	std::string result = "";
	std::list<char> tmpResult;
	const std::size_t base = strBase.size();
	boost::multiprecision::cpp_int zCopy = z;
	if (zCopy < static_cast<boost::multiprecision::cpp_int>(0))
		zCopy *= static_cast<boost::multiprecision::cpp_int>(-1);
	while (zCopy > static_cast<boost::multiprecision::cpp_int>(0))
	{
		tmpResult.push_front(strBase[static_cast<int>(zCopy % static_cast<boost::multiprecision::cpp_int>(base))]);
		zCopy /= static_cast<boost::multiprecision::cpp_int>(base);
	}
	if (z < static_cast<boost::multiprecision::cpp_int>(0))
		tmpResult.push_front('-');
	for (std::list<char>::iterator it = tmpResult.begin(); it != tmpResult.end(); it++)
		result.push_back(*it);
	return result;
}

void Solution::__solve(const long long int &limit)
{
	boost::multiprecision::cpp_int solution(0);
	for (long long int i = 1; i < limit; i++)
	{
		std::string iBaseDec = Solution::__ztosBase(i, "0123456789");
		std::string iBaseBin = Solution::__ztosBase(i, "01");
		if (Solution::__isPalindrome(iBaseDec) == true && Solution::__isPalindrome(iBaseBin) == true)
			solution += static_cast<boost::multiprecision::cpp_int>(i);
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
