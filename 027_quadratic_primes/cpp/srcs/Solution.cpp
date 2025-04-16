/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/16 14:50:41 by dcaetano         ###   ########.fr       */
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

void Solution::__solve(const long long int &limit)
{
	long long int solution = 0;
	long long int i[3], o[3] = {-limit};
	i[0] = -limit;
	while (++i[0] < limit)
	{
		i[1] = -limit - 1;
		while (++i[1] <= limit)
		{
			i[2] = 0;
			while (true)
			{
				if (Solution::__isPrime(i[2] * i[2] + i[0] * i[2] + i[1]) == false)
					break ;
				i[2]++;
			}
			if (i[2] > o[2])
				std::memcpy(o, i, sizeof(o));
		}
	}
	solution = o[0] * o[1];
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
