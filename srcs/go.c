/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:44:24 by bvalerii          #+#    #+#             */
/*   Updated: 2024/02/26 14:09:52 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_data *_)
{
	if (_->a->num > _->a->next->num)
		sa(_);
}

void	sort_3(t_data *_)
{
	int	maxi;

	maxi = find_maxi(_->a, 3);
	if (maxi == 1)
		ra(_);
	if (maxi == 2)
		rra(_);
	sort_2(_);
}

void	turk(t_data *_)
{
	t_node	*best;

	while (_->a_qty > 3 && _->b_qty < 2)
		pb(_);
	while (_->a_qty > 3)
	{
		best = cost_calc(_->a, _->b, _->a_qty, _->b_qty);
		a_to_b(_, best);
		re_ind(_);
	}
	// prt(_);
	re_ind(_);
	sort_3(_);
	// ft_printf("from A to B \n");
	// prt(_);
	sort_3(_);

	back_to_a(_);
}

void	*go(t_data *_)
{
	indx(_->a, _);
	if (is_sorted(_->a, _))
	{
		free_null(_);
		exit(0);
	}
	if (_->a_qty == 2)
		sort_2(_);
	if (_->a_qty == 3)
		sort_3(_);
	if (_->a_qty > 3)
		turk(_);
	free_null(_);
	exit(0);
}
