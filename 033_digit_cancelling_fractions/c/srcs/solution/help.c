/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 08:32:51 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/30 09:28:34 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solve_c.h"

static bool	equals_zero(mpz_t n)
{
	bool	result;
	mpz_t	zero;

	mpz_init_set_ui(zero, 0);
	result = mpz_cmp(n, zero) == 0;
	mpz_clear(zero);
	return (result);
}

void	help_compute(mpq_t product, t_help *help_ptr)
{
	mpq_t	q[2];

	if (help_ptr == NULL)
		return ;
	if (help_ptr->f[0] < 10 || help_ptr->f[1] < 10)
		return ;
	if (help_ptr->f[0] % 10 == 0 && help_ptr->f[1] % 10 == 0)
		return ;
	if (memcmp(help_ptr->f, help_ptr->ac, sizeof(long long int) * 2) == 0)
		return ;
	mpq_init(q[0]);
	mpq_init(q[1]);
	mpq_set_ui(q[0], help_ptr->f[0], help_ptr->f[1]);
	mpq_set_ui(q[1], help_ptr->ac[0], help_ptr->ac[1]);
	if (equals_zero(mpq_denref(q[0])) == true
		|| equals_zero(mpq_denref(q[1])) == true)
		return (mpq_clear(q[1]), mpq_clear(q[0]), (void)0);
	mpq_canonicalize(q[0]);
	mpq_canonicalize(q[1]);
	if (mpq_cmp(q[0], q[1]) != 0)
		return (mpq_clear(q[1]), mpq_clear(q[0]), (void)0);
	mpq_mul(product, product, q[1]);
	mpq_clear(q[1]);
	mpq_clear(q[0]);
}
