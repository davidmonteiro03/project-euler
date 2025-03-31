/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/31 12:08:10 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solve_cpp.hpp"

Solution::Solution(int argc, char **argv) : __argc(argc),
											__argv(argv) {}

Solution::Solution(const Solution &copy) : __argc(copy.__argc),
										   __argv(copy.__argv),
										   __triangle(copy.__triangle) {}

Solution &Solution::operator=(const Solution &other)
{
	if (this != &other)
	{
		this->__argc = other.__argc;
		this->__argv = other.__argv;
		this->__triangle = other.__triangle;
	}
	return *this;
}

Solution::~Solution() { this->__triangle.clear(); }

void Solution::__triangleAlloc(void)
{
	this->__triangle = std::vector<std::vector<long long int>>(this->__nLines);
	for (size_t i = 0; i < this->__triangle.size(); i++)
		this->__triangle[i] = std::vector<long long int>(i + 1);
}

void Solution::__triangleFill(const std::string &filename)
{
	if (filename.empty() || gExitStatus != EX_OK)
		return gExitStatus = EX__BASE, (void)0;
	std::fstream f(filename);
	if (f.fail())
		return gExitStatus = EX__BASE, (void)0;
	for (size_t i = 0; i < this->__nLines; i++)
		for (size_t j = 0; j < i + 1; j++)
			if (!(f >> this->__triangle[i][j]))
				return gExitStatus = EX__BASE, (void)0;
}

void Solution::fill(void)
{
	if (gExitStatus != EX_OK)
		return;
	if (this->__argc != 3)
	{
		std::cerr << "usage: " << this->__argv[0] << " <filename> <num_lines>" << std::endl;
		gExitStatus = EX_USAGE;
		return;
	}
	std::stringstream tmpNLinesSs(this->__argv[2]);
	if (!(tmpNLinesSs >> this->__nLines))
	{
		std::cerr << this->__argv[0] << ": error: '" << this->__argv[2] << "' is not an integer." << std::endl;
		gExitStatus = EX_USAGE;
		return;
	}
	this->__triangleAlloc();
	this->__triangleFill(std::string(this->__argv[1]));
}

long long int Solution::__solveRecursive(const std::size_t &i,
										 const std::size_t &j,
										 const std::size_t &row,
										 const std::size_t &col) const
{
	if (j == col)
		return 0;
	if (i == row - 1)
		return this->__triangle[i][j];
	return this->__triangle[i][j] + std::max(this->__solveRecursive(i + 1, j, row, col), this->__solveRecursive(i + 1, j + 1, row, col));
}

void Solution::execute(void) const
{
	long long int result = this->__solveRecursive(0, 0, this->__nLines, this->__nLines);
	std::cout << "Solution for [\"" << this->__argv[1] << "\", " << this->__nLines << "]: " << result << std::endl;
}
