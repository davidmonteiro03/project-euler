/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/15 11:25:30 by dcaetano         ###   ########.fr       */
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

long long int Solution::__fact(const long long int &n)
{
	if (n <= 0)
		return 1;
	return n * Solution::__fact(n - 1);
}

void Solution::__solve(const long long int &n,
					   const long long int &pos)
{
	std::string solution = "";
	for (long long int i = 0; i < n; i++)
		solution.push_back(static_cast<char>(i + '0'));
	long long int limit = Solution::__fact(n);
	for (long long int i = 0; i < limit && i < pos - 1; i++)
		std::next_permutation(solution.begin(), solution.end());
	std::cout << "Solution for " << n << " at " << pos << ": " << solution << std::endl;
}

void Solution::execute(void) const
{
	if (this->__argc != 3)
	{
		std::cerr << "usage: " << this->__argv[0] << " <n> <pos>" << std::endl;
		gExitStatus = EX_USAGE;
		return;
	}
	long long int n = 0, pos = 0;
	std::stringstream nSs(this->__argv[1]), posSs(this->__argv[2]);
	if (!(nSs >> n) || !(posSs >> pos))
	{
		std::cerr << this->__argv[0] << ": error: '" << this->__argv[1] << "' and '" << this->__argv[2] << "' are not both integers." << std::endl;
		gExitStatus = EX_DATAERR;
		return;
	}
	Solution::__solve(n, pos);
}
