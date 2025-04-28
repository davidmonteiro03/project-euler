/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/28 12:40:43 by dcaetano         ###   ########.fr       */
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

long long int Solution::__checkPandigital(const long long int &n,
										  const long long int &l,
										  const std::string &ds)
{
	long long int result = 0;
	std::vector<long long int> ps;
	for (long long int a = 1; a < l; a++)
	{
		for (long long int b = 1; b < l; b++)
		{
			long long int prod = a * b;
			std::stringstream rSs;
			rSs << a << b << prod;
			std::string r = rSs.str();
			if (r.size() != static_cast<std::size_t>(n))
				continue;
			std::sort(r.begin(), r.end());
			if (r != ds)
				continue;
			if (std::find(ps.begin(), ps.end(), prod) != ps.end())
				continue ;
			ps.push_back(prod);
			result += prod;
		}
	}
	return result;
}

void Solution::__solve(const long long int &n)
{
	long long int solution = 0;
	if (n < 1 || n > 9)
		return;
	long long int limit = std::pow(10, n / 2);
	std::string digits = "";
	for (long long int i = 0; i < n; i++)
		digits.push_back(static_cast<char>(i + 1) + '0');
	solution = Solution::__checkPandigital(n, limit, digits);
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
