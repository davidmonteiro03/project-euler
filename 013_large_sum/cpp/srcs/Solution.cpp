/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/29 00:32:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solve_cpp.hpp"

Solution::Solution(int argc, char **argv) : __argc(argc),
											__argv(argv) {}

Solution::Solution(const Solution &copy) : __argc(copy.__argc),
										   __argv(copy.__argv),
										   __nums(copy.__nums) {}

Solution &Solution::operator=(const Solution &other)
{
	if (this != &other)
	{
		this->__argc = other.__argc;
		this->__argv = other.__argv;
		this->__nums = other.__nums;
	}
	return *this;
}

Solution::~Solution() {}

void Solution::__fillNums(const std::string &filename)
{
	if (filename.empty() || gExitStatus != EX_OK)
		return gExitStatus = EX__BASE, (void)0;
	std::fstream f(filename);
	if (f.fail())
		return gExitStatus = EX__BASE, (void)0;
	while (!f.eof())
	{
		std::string tmp = "";
		f >> tmp;
		if (tmp.empty())
			continue;
		this->__nums.push_back(tmp);
	}
}

void Solution::fill(void)
{
	if (gExitStatus != EX_OK)
		return;
	if (this->__argc != 2)
	{
		std::cerr << "usage: " << this->__argv[0] << " <filename>" << std::endl;
		gExitStatus = EX_USAGE;
		return;
	}
	this->__fillNums(std::string(this->__argv[1]));
}

long long int Solution::__extractFirst10DigitsFromSum(void) const
{
	boost::multiprecision::cpp_int sum(0);
	for (size_t i = 0; i < this->__nums.size(); i++)
	{
		boost::multiprecision::cpp_int tmp(this->__nums[i]);
		sum += tmp;
	}
	std::stringstream sumSs;
	sumSs << sum;
	std::string resultStr = sumSs.str().substr(0, 10);
	boost::multiprecision::cpp_int resultBoosted(resultStr);
	long long int result = resultBoosted.convert_to<long long int>();
	return result;
}

void Solution::execute(void) const
{
	if (gExitStatus != EX_OK)
		return;
	long long int result = this->__extractFirst10DigitsFromSum();
	std::cout << "Solution for \"" << this->__argv[1] << "\": " << result << std::endl;
}
