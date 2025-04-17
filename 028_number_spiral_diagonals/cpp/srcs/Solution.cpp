/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/17 09:17:35 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solve_cpp.hpp"

Solution::Solution(int argc, char **argv) : __argc(argc),
											__argv(argv),
											__spiral(),
											__m(0),
											__n(0) {}

Solution::Solution(const Solution &copy) : __argc(copy.__argc),
										   __argv(copy.__argv),
										   __spiral(copy.__spiral),
										   __m(copy.__m),
										   __n(copy.__n) {}

Solution &Solution::operator=(const Solution &other)
{
	if (this != &other)
	{
		this->__argc = other.__argc;
		this->__argv = other.__argv;
		this->__spiral = other.__spiral;
		this->__m = other.__m;
		this->__n = other.__n;
	}
	return *this;
}

Solution::~Solution() { this->__spiral.clear(); }

void Solution::__fillSpiral(void)
{
	if (this->__spiral.empty() || this->__m == 0 || this->__n == 0 || this->__m % 2 == 0 || this->__n % 2 == 0 || this->__m != this->__n)
		return;
	size_t x = this->__m / 2, y = this->__n / 2;
	short int dir = 0;
	size_t count = 1;
	size_t steps = 1;
	this->__spiral[x][y] = count++;
	while (count <= this->__m * this->__n)
	{
		for (std::size_t s = 0; s < 2; s++)
		{
			for (std::size_t step = 0; step < steps; step++)
			{
				if (count > this->__m * this->__n)
					break;
				switch (dir)
				{
				case 0:
					y++;
					break;
				case 1:
					x++;
					break;
				case 2:
					y--;
					break;
				default:
					x--;
					break;
				}
				this->__spiral[x][y] = count++;
			}
			dir = (dir + 1) % 4;
		}
		steps++;
	}
}

void Solution::fill(void)
{
	if (gExitStatus != EX_OK)
		return;
	if (this->__argc != 3)
	{
		std::cerr << "usage: " << this->__argv[0] << " <m> <n>" << std::endl;
		gExitStatus = EX_USAGE;
		return;
	}
	long long int m = 0, n = 0;
	std::stringstream mSs(this->__argv[1]), nSs(this->__argv[2]);
	if (!(mSs >> m) || !(nSs >> n))
	{
		std::cerr << this->__argv[0] << ": error: '" << this->__argv[1] << "' and '" << this->__argv[2] << "' are not both integers." << std::endl;
		gExitStatus = EX_DATAERR;
		return;
	}
	if (m <= 0 || n <= 0 || m % 2 == 0 || n % 2 == 0 || m != n)
		return;
	this->__m = static_cast<std::size_t>(m);
	this->__n = static_cast<std::size_t>(n);
	this->__spiral = std::vector<std::vector<long long int>>(this->__m);
	for (std::size_t i = 0; i < this->__m; i++)
		this->__spiral[i] = std::vector<long long int>(this->__n);
	this->__fillSpiral();
}

void Solution::__solve(const std::vector<std::vector<long long int>> &spiral,
					   const std::size_t &m,
					   const std::size_t &n)
{
	long long int solution = 0;
	if (spiral.empty() || m == 0 || n == 0 || m % 2 == 0 || n % 2 == 0 || m != n)
		return;
	for (std::size_t i = 0; i < m; i++)
		for (std::size_t j = 0; j < n; j++)
			solution += spiral[i][j] * (i == j || i == n - j - 1);
	std::cout << "Solution for " << m << " by " << n << ": " << solution << std::endl;
}

void Solution::execute(void) const
{
	if (this->__spiral.empty() || gExitStatus != EX_OK)
		return;
	Solution::__solve(this->__spiral, this->__m, this->__n);
}
