/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 08:55:57 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/27 14:42:20 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solve_c.h"

int	g_exit_status = EX_OK;

int	main(int argc, char **argv)
{
	t_solution	solution;

	solution_init(&solution, argc, argv);
	solution_execute(&solution);
	return (g_exit_status);
}
