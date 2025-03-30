/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/30 16:30:53 by dcaetano         ###   ########.fr       */
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

void Solution::__solve(const long long int &k,
					   const long long int &n)
{
	boost::multiprecision::cpp_int solution = 0;
	boost::multiprecision::cpp_int fact1 = 1;
	boost::multiprecision::cpp_int fact2 = 1;
	boost::multiprecision::cpp_int fact3 = 1;
	for (long long int i = k + n; i > 1; i--)
		fact1 *= i;
	for (long long int i = k; i > 1; i--)
		fact2 *= i;
	for (long long int i = n; i > 1; i--)
		fact3 *= i;
	solution = fact1 / (fact2 * fact3);
	std::cout << "Solution for [" << k << ", " << n << "]: " << solution << std::endl;
}

void Solution::execute(void) const
{
	if (this->__argc != 3)
	{
		std::cerr << "usage: " << this->__argv[0] << " <k> <n>" << std::endl;
		gExitStatus = EX_USAGE;
		return;
	}
	long long int k = 0;
	long long int n = 0;
	std::stringstream tmpKSs(this->__argv[1]);
	std::stringstream tmpNSs(this->__argv[2]);
	if (!(tmpKSs >> k) || !(tmpNSs >> n))
	{
		std::cerr << this->__argv[0] << ": error: '" << this->__argv[1] << "' and '" << this->__argv[2] << "' are not both integers." << std::endl;
		gExitStatus = EX_DATAERR;
		return;
	}
	Solution::__solve(k, n);
}
