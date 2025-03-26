/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/26 19:59:37 by dcaetano         ###   ########.fr       */
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

void Solution::__solve(const long long int &start, const long long int &end)
{
	long long int solution = 0;
	for (long long int i = start; i < end; i++)
		;
	std::cout << "Solution for [" << start << ", " << end << "]: " << solution << std::endl;
}

long long int Solution::__read_helper(const int &i, const long long int &value)
{
	long long int result = value;
	if (i < this->__argc)
	{
		std::stringstream tmp(this->__argv[i]);
		tmp >> result;
	}
	else
		std::cin >> result;
	return result;
}

void Solution::execute(void)
{
	for (int i = 1; i < this->__argc;)
	{
		long long int start = this->__read_helper(i++, start);
		long long int end = this->__read_helper(i++, end);
		this->__solve(start, end);
	}
}
