/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 11:43:25 by dcaetano         ###   ########.fr       */
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

long long int Solution::__findPythagoreanTriplet(const long long int &n)
{
	for (long long int a = 1; a <= n; a++)
		for (long long int b = a + 1; b <= n; b++)
			for (long long int c = b + 1; c <= n; c++)
				if (a * a + b * b == c * c && a + b + c == n)
					return a * b * c;
	return 0;
}

void Solution::__solve(const long long int &n)
{
	long long int solution = Solution::__findPythagoreanTriplet(n);
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
