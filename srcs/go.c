/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:44:24 by bvalerii          #+#    #+#             */
/*   Updated: 2024/03/05 17:08:55 by bvalerii         ###   ########.fr       */
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

void	sort_45(t_data *_)
{
	if (_->a_qty == 4)
		pb(_);
	else if (_->a_qty == 5)
	{
		pb(_);
		pb(_);
	}
	re_ind(_);
	sort_3(_);
	back_to_a(_);
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
	re_ind(_);
	sort_3(_);
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
	if (_->a_qty > 3 && _->a_qty < 6)
		sort_45(_);
	if (_->a_qty > 5)
		turk(_);
	free_null(_);
	exit(0);
}
