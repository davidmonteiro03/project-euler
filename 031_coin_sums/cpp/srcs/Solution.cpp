/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/17 14:13:52 by dcaetano         ###   ########.fr       */
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

long long int Solution::__countRecursive(const std::vector<long long int> &coins,
										 const std::size_t &n,
										 const long long int &sum)
{
	if (sum == 0)
		return 1;
	if (sum < 0 || n == 0)
		return 0;
	return Solution::__countRecursive(coins, n, sum - coins[n - 1]) + Solution::__countRecursive(coins, n - 1, sum);
}

void Solution::__solve(const long long int &sum)
{
	static const std::vector<long long int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
	long long int solution = __countRecursive(coins, coins.size(), sum);
	std::cout << "Solution for " << sum << ": " << solution << std::endl;
}

void Solution::execute(void) const
{
	if (this->__argc != 2)
	{
		std::cerr << "usage: " << this->__argv[0] << " <sum>" << std::endl;
		gExitStatus = EX_USAGE;
		return;
	}
	long long int sum = 0;
	std::stringstream tmp(this->__argv[1]);
	if (!(tmp >> sum))
	{
		std::cerr << this->__argv[0] << ": error: '" << this->__argv[1] << "' is not an integer." << std::endl;
		gExitStatus = EX_DATAERR;
		return;
	}
	Solution::__solve(sum);
}
