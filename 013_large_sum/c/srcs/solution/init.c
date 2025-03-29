/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:50:57 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/28 23:44:35 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

void	solution_init(t_solution *solution, int argc, char **argv)
{
	if (solution == NULL)
		return ;
	solution->argc = argc;
	solution->argv = argv;
	bzero(solution->nums, sizeof(solution->nums));
	solution->length = sizeof(solution->nums) / sizeof(solution->nums[0]);
	solution->size = sizeof(solution->nums[0]) / sizeof(solution->nums[0][0]);
}
