/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 22:49:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solve_cpp.hpp"

Solution::Solution(int argc, char **argv) : __argc(argc),
											__argv(argv),
											__m(sizeof(__grid) / sizeof(__grid[0])),
											__n(sizeof(__grid[0]) / sizeof(__grid[0][0])) { bzero(this->__grid, sizeof(this->__grid)); }

Solution::Solution(const Solution &copy) : __argc(copy.__argc),
										   __argv(copy.__argv),
										   __m(copy.__m),
										   __n(copy.__n) { std::memcpy(this->__grid, copy.__grid, sizeof(this->__grid)); }

Solution &Solution::operator=(const Solution &other)
{
	if (this != &other)
	{
		this->__argc = other.__argc;
		this->__argv = other.__argv;
		this->__m = other.__m;
		this->__n = other.__n;
		std::memcpy(this->__grid, other.__grid, sizeof(this->__grid));
	}
	return *this;
}

Solution::~Solution() {}

void Solution::__fillGrid(const std::string &filename)
{
	if (filename.empty() || gExitStatus != EX_OK)
	{
		gExitStatus = EX__BASE;
		return;
	}
	std::fstream f(filename);
	if (f.fail())
	{
		gExitStatus = EX__BASE;
		return;
	}
	for (size_t i = 0; i < this->__m; i++)
	{
		for (size_t j = 0; j < this->__n; j++)
		{
			if (!(f >> this->__grid[i][j]))
			{
				gExitStatus = EX__BASE;
				return;
			}
		}
	}
}

void Solution::fill(void)
{
	if (gExitStatus != EX_OK)
		return;
	if (this->__argc != 2)
	{
		std::cerr << "usage: " << this->__argv[0] << " <filename>" << std::endl;
		gExitStatus = EX_USAGE;
		return;
	}
	this->__fillGrid(std::string(this->__argv[1]));
}

long long int Solution::__computeMaxHorizProd(const size_t &len) const
{
	if (len == 0)
		return (0);
	long long int result = 0;
	for (size_t i = 0; i < this->__m - len + 1; i++)
	{
		for (size_t j = 0; j < this->__n - len + 1; j++)
		{
			long long int prod = 1;
			for (size_t k = 0; k < len; k++)
				prod *= this->__grid[i][j + k];
			result = std::max(result, prod);
		}
	}
	return result;
}

long long int Solution::__computeMaxVertProd(const size_t &len) const
{
	if (len == 0)
		return (0);
	long long int result = 0;
	for (size_t i = 0; i < this->__m - len + 1; i++)
	{
		for (size_t j = 0; j < this->__n - len + 1; j++)
		{
			long long int prod = 1;
			for (size_t k = 0; k < len; k++)
				prod *= this->__grid[i + k][j];
			result = std::max(result, prod);
		}
	}
	return result;
}

long long int Solution::__computeMaxDiagProd(const size_t &len) const
{
	if (len == 0)
		return (0);
	long long int result = 0;
	for (size_t i = 0; i < this->__m - len + 1; i++)
	{
		for (size_t j = 0; j < this->__n - len + 1; j++)
		{
			long long int prod = 1;
			for (size_t k = 0; k < len; k++)
				prod *= this->__grid[i + k][j + k];
			result = std::max(result, prod);
		}
	}
	return result;
}

long long int Solution::__computeMaxRDiagProd(const size_t &len) const
{
	if (len == 0)
		return (0);
	long long int result = 0;
	for (size_t i = 0; i < this->__m - len + 1; i++)
	{
		for (size_t j = 0; j < this->__n - len + 1; j++)
		{
			long long int prod = 1;
			for (size_t k = 0; k < len; k++)
				prod *= this->__grid[i + k][j + len - k - 1];
			result = std::max(result, prod);
		}
	}
	return result;
}

void Solution::execute(void) const
{
	if (gExitStatus != EX_OK)
		return;
	long long int result = 0;
	long long int maxHorizProd = this->__computeMaxHorizProd(4);
	long long int maxVertProd = this->__computeMaxVertProd(4);
	long long int maxDiagProd = this->__computeMaxDiagProd(4);
	long long int maxRDiagProd = this->__computeMaxRDiagProd(4);
	result = std::max(result, maxHorizProd);
	result = std::max(result, maxVertProd);
	result = std::max(result, maxDiagProd);
	result = std::max(result, maxRDiagProd);
	std::cout << "Solution for \"" << this->__argv[1] << "\": " << result << std::endl;
}
