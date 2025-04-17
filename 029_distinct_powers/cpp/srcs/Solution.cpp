/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/17 13:05:10 by dcaetano         ###   ########.fr       */
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

void Solution::__solve(const long long int &start,
					   const long long int &end)
{
	if (end < start)
		return;
	std::size_t solution = 0;
	std::vector<boost::multiprecision::cpp_int> powers;
	for (long long int a = start; a <= end; a++)
		for (long long int b = start; b <= end; b++)
			powers.push_back(boost::multiprecision::pow(boost::multiprecision::cpp_int(a), b));
	std::sort(powers.begin(), powers.end());
	solution = powers.size();
	for (std::size_t i = 0; i < powers.size() - 1; i++)
		if (powers[i] == powers[i + 1])
			solution--;
	std::cout << "Solution for [" << start << ", " << end << "]: " << solution << std::endl;
}

void Solution::execute(void) const
{
	if (this->__argc != 3)
	{
		std::cerr << "usage: " << this->__argv[0] << " <start> <end>" << std::endl;
		gExitStatus = EX_USAGE;
		return;
	}
	long long int start = 0, end = 0;
	std::stringstream startSs(this->__argv[1]), endSs(this->__argv[2]);
	if (!(startSs >> start) || !(endSs >> end))
	{
		std::cerr << this->__argv[0] << ": error: '" << this->__argv[1] << "' and '" << this->__argv[2] << "' are not both integers." << std::endl;
		gExitStatus = EX_DATAERR;
		return;
	}
	Solution::__solve(start, end);
}
