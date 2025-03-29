/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:41:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/28 23:44:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLUTION_H
# define SOLUTION_H

# include <sys/types.h>

typedef struct s_solution
{
	int		argc;
	char	**argv;
	char	nums[100][51];
	size_t	length;
	size_t	size;
}			t_solution;

void		solution_init(t_solution *solution, int argc, char **argv);
void		solution_fill(t_solution *solution);
void		solution_execute(t_solution *solution);

#endif
