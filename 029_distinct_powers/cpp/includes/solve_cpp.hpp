/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_cpp.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:23:06 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/17 12:55:51 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

extern "C"
{
#include <sysexits.h>
}

class Solution;

#include "Solution.hpp"

extern int gExitStatus;
