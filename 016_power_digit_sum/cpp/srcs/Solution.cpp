/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/30 16:41:33 by dcaetano         ###   ########.fr       */
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

void Solution::__solve(const long long int &base,
					   const long long int &exp)
{
	boost::multiprecision::cpp_int solution = 0;
	boost::multiprecision::cpp_int powValue = 1;
	for (long long int i = 0; i < exp; i++)
		powValue *= base;
	std::stringstream powSs;
	powSs << powValue;
	std::string powStr = powSs.str();
	for (size_t i = 0; i < powStr.size(); i++)
		solution += powStr[i] - '0';
	std::cout << "Solution for [" << base << ", " << exp << "]: " << solution << std::endl;
}

void Solution::execute(void) const
{
	if (this->__argc != 3)
	{
		std::cerr << "usage: " << this->__argv[0] << " <base> <exp>" << std::endl;
		gExitStatus = EX_USAGE;
		return;
	}
	long long int base = 0;
	long long int exp = 0;
	std::stringstream tmpBaseSs(this->__argv[1]);
	std::stringstream tmpExpSs(this->__argv[2]);
	if (!(tmpBaseSs >> base) || !(tmpExpSs >> exp))
	{
		std::cerr << this->__argv[0] << ": error: '" << this->__argv[1] << "' and '" << this->__argv[2] << "' are not both integers." << std::endl;
		gExitStatus = EX_DATAERR;
		return;
	}
	Solution::__solve(base, exp);
}
