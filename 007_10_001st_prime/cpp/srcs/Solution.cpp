/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 08:57:31 by dcaetano         ###   ########.fr       */
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

long long int Solution::__findNextPrime(const long long int &n)
{
	if (n <= 1)
		return Solution::__findNextPrime(n + 1);
	if (n <= 3)
		return n;
	if (n % 2 == 0 || n % 3 == 0)
		return Solution::__findNextPrime(n + 1);
	for (long long int i = 5; i * i <= n && i * i > 0; i += 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return Solution::__findNextPrime(n + 1);
	return n;
}

void Solution::__solve(const long long int &n)
{
	long long int solution = Solution::__findNextPrime(0);
	long long int tmp_n = n;
	while (--tmp_n > 0)
		solution = Solution::__findNextPrime(solution + 1);
	std::cout << "Solution for " << n << ": " << solution << std::endl;
}

void Solution::execute(void) const
{
	long long int n = 0;
	if (this->__argc < 2)
	{
		std::cin >> n;
		Solution::__solve(n);
		return;
	}
	for (int i = 1; i < this->__argc; i++)
	{
		std::stringstream tmp(this->__argv[i++]);
		tmp >> n;
		Solution::__solve(n);
	}
}
