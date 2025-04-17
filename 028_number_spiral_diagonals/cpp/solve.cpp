/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 08:55:57 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/17 09:03:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solve_cpp.hpp"

int gExitStatus = EX_OK;

int main(int argc, char **argv)
{
	Solution solution(argc, argv);
	solution.fill();
	solution.execute();
	return gExitStatus;
}
