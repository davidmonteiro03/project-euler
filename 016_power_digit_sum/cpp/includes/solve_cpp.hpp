/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_cpp.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:23:06 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/30 15:11:35 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/math/special_functions/factorials.hpp>

extern "C"
{
#include <sysexits.h>
}

class Solution;

#include "Solution.hpp"

extern int gExitStatus;
