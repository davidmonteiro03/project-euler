/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/26 13:14:36 by dcaetano         ###   ########.fr       */
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

void Solution::__solve(const long long int &n)
{
	long long int solution = 0;
	for (long long int first = 1, second = 1, next = first + second; first < n;)
	{
		solution += first * (first % 2 == 0);
		first = second;
		second = next;
		next = first + second;
	}
	std::cout << "Solution for " << n << ": " << solution << std::endl;
}

void Solution::execute(void) const
{
	long long int n = 0;
	if (this->__argc < 2)
	{
		std::cin >> n;
		this->__solve(n);
		return;
	}
	for (int i = 1; i < this->__argc; i++)
	{
		std::stringstream tmp(this->__argv[i++]);
		tmp >> n;
		this->__solve(n);
	}
}
