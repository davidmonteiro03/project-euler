/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solution.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/01 14:57:54 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solve_cpp.hpp"

Solution::Solution(int argc, char **argv) : __argc(argc),
											__argv(argv) {}

Solution::Solution(const Solution &copy) : __argc(copy.__argc),
										   __argv(copy.__argv),
										   __names(copy.__names) {}

Solution &Solution::operator=(const Solution &other)
{
	if (this != &other)
	{
		this->__argc = other.__argc;
		this->__argv = other.__argv;
		this->__names = other.__names;
	}
	return *this;
}

Solution::~Solution() { this->__names.clear(); }

void Solution::__fillNames(const std::string &filename)
{
	if (filename.empty() || gExitStatus != EX_OK)
		return;
	std::fstream f(filename);
	if (f.fail())
		return gExitStatus = EX__BASE, (void)0;
	while (!f.eof())
	{
		std::string word = "";
		std::getline(f, word, ',');
		if (word.empty())
			continue;
		size_t start = word.find_first_of('\"');
		size_t end = word.find_last_of('\"');
		std::string name = word.substr(start + 1, end - start - 1);
		if (name.empty())
			continue;
		this->__names.push_back(name);
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
	this->__fillNames(std::string(this->__argv[1]));
}

long long int Solution::__getLetterCode(const char &c)
{
	if (c >= 'A' && c <= 'Z')
		return c - 65 + 1;
	if (c >= 'a' && c <= 'z')
		return c - 97 + 1;
	return (0);
}

long long int Solution::__getNameScore(const std::string &name,
							 const long long int &pos)
{
	if (name.empty() || pos < 0)
		return 0;
	long long int result = 0;
	for (size_t i = 0; i < name.size(); i++)
		result += Solution::__getLetterCode(name[i]);
	result *= pos + 1;
	return result;
}

void Solution::__solve(const std::vector<std::string> &names,
					   const std::string &filename)
{
	long long int solution = 0;
	if (names.empty() || filename.empty())
		return;
	std::vector<std::string> copy(names);
	std::sort(copy.begin(), copy.end());
	for (size_t i = 0; i < copy.size(); i++)
		solution += Solution::__getNameScore(copy[i], i);
	std::cout << "Solution for " << filename << ": " << solution << std::endl;
}

void Solution::execute(void) const
{
	if (this->__names.empty() || gExitStatus != EX_OK)
		return;
	Solution::__solve(this->__names, std::string(this->__argv[1]));
}
