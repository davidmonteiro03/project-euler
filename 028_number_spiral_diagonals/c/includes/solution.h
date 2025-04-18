/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:41:55 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/17 08:31:28 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLUTION_H
# define SOLUTION_H

# include <stddef.h>

typedef struct s_solution
{
	int				argc;
	char			**argv;
	long long int	**spiral;
	size_t			m;
	size_t			n;
}					t_solution;

void				solution_init(t_solution *solution, int argc, char **argv);
void				solution_fill(t_solution *solution);
void				solution_execute(t_solution *solution);

#endif
